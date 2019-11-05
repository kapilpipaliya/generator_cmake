#include "./data.h"
#include <QtDebug>
#include "./treeitem.h"

#include <QStringList>
namespace widgets {
Data::Data(QObject *parent) : QAbstractItemModel(parent) {
  rootItem = new TreeItem({tr("column name"), tr("type"), "isnull", "default"});
  setupModelData();
}

Data::~Data() { delete rootItem; }

QModelIndex Data::index(int row, int column, const QModelIndex &parent) const {
  if (!hasIndex(row, column, parent)) return QModelIndex();

  TreeItem *parentItem;

  if (!parent.isValid())
    parentItem = rootItem;
  else
    parentItem = static_cast<TreeItem *>(parent.internalPointer());

  TreeItem *childItem = parentItem->child(row);
  if (childItem)
    return createIndex(row, column, childItem);  // use createIndex to create
  return QModelIndex();
}

QModelIndex Data::parent(const QModelIndex &child) const {
  if (!child.isValid())
    return QModelIndex();  // if no parent return invalid index

  TreeItem *childItem = static_cast<TreeItem *>(child.internalPointer());
  TreeItem *parentItem = childItem->parentItem();

  if (parentItem == rootItem) return QModelIndex();

  return createIndex(parentItem->row(), 0, parentItem);
}

int Data::rowCount(const QModelIndex &parent) const {
  TreeItem *parentItem;
  if (parent.column() > 0) return 0;

  if (!parent.isValid())
    parentItem = rootItem;
  else
    parentItem = static_cast<TreeItem *>(parent.internalPointer());

  return parentItem->childCount();
}

int Data::columnCount(const QModelIndex &parent) const {
  if (parent.isValid())
    return static_cast<TreeItem *>(parent.internalPointer())->columnCount();
  return rootItem->columnCount();
}

QVariant Data::data(const QModelIndex &index, int role) const {
  if (!index.isValid()) return QVariant();

  if (role != Qt::DisplayRole) return QVariant();

  TreeItem *item = static_cast<TreeItem *>(index.internalPointer());

  return item->data(index.column());
}

Qt::ItemFlags Data::flags(const QModelIndex &index) const {
  if (!index.isValid()) return Qt::NoItemFlags;

  return QAbstractItemModel::flags(index);
}

QVariant Data::headerData(int section, Qt::Orientation orientation,
                          int role) const {
  if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
    return rootItem->data(section);

  return QVariant();
}
TreeItem *Data::getItem(const QModelIndex &index) const {
  if (index.isValid()) {
    TreeItem *item = static_cast<TreeItem *>(index.internalPointer());
    if (item) return item;
  }
  return rootItem;
}
void Data::addTable(QString table_name, QString columns) {
  {
    auto item = new TreeItem({table_name, "", "", ""}, rootItem);
    auto lines = columns.split(",");
    for (auto it : lines) {
      it = it.trimmed();
      auto words = it.split(" ");
      QVector<QVariant> v;
      for (auto it2 : words) {
        v << it2;
      }
      item->appendChild(new TreeItem(v, item));
    }
    rootItem->appendChild(item);
  }
}
void Data::setupModelData() {
  addTable("announcements", R"(
        id integer NOT_NULL,
        text text,
        show_until date,
        active boolean DEFAULT=false,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone
    )");

  addTable("ar_internal_metadata", R"(
        key character_varying NOT_NULL,
        value character_varying,
        created_at timestamp(6)_without_time_zone NOT_NULL,
        updated_at timestamp(6)_without_time_zone NOT_NULL
    )");

  addTable("attachable_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        attachment_id integer NOT_NULL,
        filename character_varying DEFAULT=''::character_varying NOT_NULL
    )");

  addTable("attachment_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        container_id integer,
        container_type character_varying(30),
        filename character_varying DEFAULT=''::character_varying NOT_NULL,
        disk_filename character_varying DEFAULT=''::character_varying NOT_NULL,
        filesize integer DEFAULT=0 NOT_NULL,
        content_type character_varying DEFAULT=''::character_varying,
        digest character_varying(40) DEFAULT=''::character_varying NOT_NULL,
        downloads integer DEFAULT=0 NOT_NULL,
        author_id integer DEFAULT=0 NOT_NULL,
        description text
    )");

  addTable("attachments", R"(
        id integer NOT_NULL,
        container_id integer,
        container_type character_varying(30),
        filename character_varying DEFAULT=''::character_varying NOT_NULL,
        disk_filename character_varying DEFAULT=''::character_varying NOT_NULL,
        filesize integer DEFAULT=0 NOT_NULL,
        content_type character_varying DEFAULT=''::character_varying,
        digest character_varying(40) DEFAULT=''::character_varying NOT_NULL,
        downloads integer DEFAULT=0 NOT_NULL,
        author_id integer DEFAULT=0 NOT_NULL,
        created_at timestamp_without_time_zone,
        description character_varying,
        file character_varying,
        fulltext text,
        fulltext_tsv tsvector,
        file_tsv tsvector,
        updated_at timestamp_without_time_zone
    )");

  addTable("attribute_help_texts", R"(
        id integer NOT_NULL,
        help_text text NOT_NULL,
        type character_varying NOT_NULL,
        attribute_name character_varying NOT_NULL,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("auth_sources", R"(
        id integer NOT_NULL,
        type character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        name character_varying(60) DEFAULT=''::character_varying NOT_NULL,
        host character_varying(60),
        port integer,
        account character_varying,
        account_password character_varying DEFAULT=''::character_varying,
        base_dn character_varying,
        attr_login character_varying(30),
        attr_firstname character_varying(30),
        attr_lastname character_varying(30),
        attr_mail character_varying(30),
        onthefly_register boolean DEFAULT=false NOT_NULL,
        attr_admin character_varying,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        tls_mode integer DEFAULT=0 NOT_NULL
    )");

  addTable("categories", R"(
        id integer NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL,
        name character_varying(256) DEFAULT=''::character_varying NOT_NULL,
        assigned_to_id integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("changes", R"(
        id integer NOT_NULL,
        changeset_id integer NOT_NULL,
        action character_varying(1) DEFAULT=''::character_varying NOT_NULL,
        path text NOT_NULL,
        from_path text,
        from_revision character_varying,
        revision character_varying,
        branch character_varying
    )");

  addTable("changeset_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        repository_id integer NOT_NULL,
        revision character_varying NOT_NULL,
        committer character_varying,
        committed_on timestamp_without_time_zone NOT_NULL,
        comments text,
        commit_date date,
        scmid character_varying,
        user_id integer
    )");

  addTable("changesets", R"(
        id integer NOT_NULL,
        repository_id integer NOT_NULL,
        revision character_varying NOT_NULL,
        committer character_varying,
        committed_on timestamp_without_time_zone NOT_NULL,
        comments text,
        commit_date date,
        scmid character_varying,
        user_id integer
    )");

  addTable("changesets_work_packages", R"(
        changeset_id integer NOT_NULL,
        work_package_id integer NOT_NULL
    )");

  addTable("colors", R"(
        id integer NOT_NULL,
        name character_varying NOT_NULL,
        hexcode character_varying NOT_NULL,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone
    )");

  addTable("comments", R"(
        id integer NOT_NULL,
        commented_type character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        commented_id integer DEFAULT=0 NOT_NULL,
        author_id integer DEFAULT=0 NOT_NULL,
        comments text,
        created_on timestamp_without_time_zone NOT_NULL,
        updated_on timestamp_without_time_zone NOT_NULL
    )");

  addTable("cost_entries", R"(
        id integer NOT_NULL,
        user_id integer NOT_NULL,
        project_id integer NOT_NULL,
        work_package_id integer NOT_NULL,
        cost_type_id integer NOT_NULL,
        units double precision NOT_NULL,
        spent_on date NOT_NULL,
        created_on timestamp_without_time_zone NOT_NULL,
        updated_on timestamp_without_time_zone NOT_NULL,
        comments character_varying NOT_NULL,
        blocked boolean DEFAULT=false NOT_NULL,
        overridden_costs numeric(15,4),
        costs numeric(15,4),
        rate_id integer,
        tyear integer NOT_NULL,
        tmonth integer NOT_NULL,
        tweek integer NOT_NULL
    )");

  addTable("cost_object_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        project_id integer NOT_NULL,
        author_id integer NOT_NULL,
        subject character_varying NOT_NULL,
        description text,
        fixed_date date NOT_NULL,
        created_on timestamp_without_time_zone
    )");

  addTable("cost_objects", R"(
        id integer NOT_NULL,
        project_id integer NOT_NULL,
        author_id integer NOT_NULL,
        subject character_varying NOT_NULL,
        description text NOT_NULL,
        type character_varying NOT_NULL,
        fixed_date date NOT_NULL,
        created_on timestamp_without_time_zone,
        updated_on timestamp_without_time_zone
    )");

  addTable("cost_queries", R"(
        id integer NOT_NULL,
        user_id integer NOT_NULL,
        project_id integer,
        name character_varying NOT_NULL,
        is_public boolean DEFAULT=false NOT_NULL,
        created_on timestamp_without_time_zone NOT_NULL,
        updated_on timestamp_without_time_zone NOT_NULL,
        serialized character_varying(2000) NOT_NULL
    )");

  addTable("cost_types", R"(
        id integer NOT_NULL,
        name character_varying NOT_NULL,
        unit character_varying NOT_NULL,
        unit_plural character_varying NOT_NULL,
        "default" boolean DEFAULT=false NOT_NULL,
        deleted_at timestamp_without_time_zone
    )");

  addTable("custom_actions", R"(
        id integer NOT_NULL,
        name character_varying,
        actions text,
        description text,
        "position" integer
    )");

  addTable("custom_actions_projects", R"(
        id integer NOT_NULL,
        project_id bigint,
        custom_action_id bigint
    )");

  addTable("custom_actions_roles", R"(
        id integer NOT_NULL,
        role_id bigint,
        custom_action_id bigint
    )");

  addTable("custom_actions_statuses", R"(
        id integer NOT_NULL,
        status_id bigint,
        custom_action_id bigint
    )");

  addTable("custom_actions_types", R"(
        id integer NOT_NULL,
        type_id bigint,
        custom_action_id bigint
    )");

  addTable("custom_fields", R"(
        id integer NOT_NULL,
        type character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        field_format character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        regexp character_varying DEFAULT=''::character_varying,
        min_length integer DEFAULT=0 NOT_NULL,
        max_length integer DEFAULT=0 NOT_NULL,
        is_required boolean DEFAULT=false NOT_NULL,
        is_for_all boolean DEFAULT=false NOT_NULL,
        is_filter boolean DEFAULT=false NOT_NULL,
        "position" integer DEFAULT=1,
        searchable boolean DEFAULT=false,
        editable boolean DEFAULT=true,
        visible boolean DEFAULT=true NOT_NULL,
        multi_value boolean DEFAULT=false,
        default_value text,
        name character_varying(255) DEFAULT=NULL::character_varying,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone
    )");

  addTable("custom_fields_projects", R"(
        custom_field_id integer DEFAULT=0 NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL
    )");

  addTable("custom_fields_types", R"(
        custom_field_id integer DEFAULT=0 NOT_NULL,
        type_id integer DEFAULT=0 NOT_NULL
    )");

  addTable("custom_options", R"(
        id integer NOT_NULL,
        custom_field_id integer,
        "position" integer,
        default_value boolean,
        value text,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone
    )");

  addTable("custom_styles", R"(
        id integer NOT_NULL,
        logo character_varying,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        favicon character_varying,
        touch_icon character_varying
    )");

  addTable("custom_values", R"(
        id integer NOT_NULL,
        customized_type character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        customized_id integer DEFAULT=0 NOT_NULL,
        custom_field_id integer DEFAULT=0 NOT_NULL,
        value text
    )");

  addTable("customizable_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        custom_field_id integer NOT_NULL,
        value text
    )");

  addTable("delayed_jobs", R"(
        id integer NOT_NULL,
        priority integer DEFAULT=0,
        attempts integer DEFAULT=0,
        handler text,
        last_error text,
        run_at timestamp_without_time_zone,
        locked_at timestamp_without_time_zone,
        failed_at timestamp_without_time_zone,
        locked_by character_varying,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone,
        queue character_varying
    )");

  addTable("design_colors", R"(
        id integer NOT_NULL,
        variable character_varying,
        hexcode character_varying,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("document_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL,
        category_id integer DEFAULT=0 NOT_NULL,
        title character_varying(60) DEFAULT=''::character_varying NOT_NULL,
        description text,
        created_on timestamp_without_time_zone
    )");

  addTable("documents", R"(
        id integer NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL,
        category_id integer DEFAULT=0 NOT_NULL,
        title character_varying(60) DEFAULT=''::character_varying NOT_NULL,
        description text,
        created_on timestamp_without_time_zone
    )");

  addTable("done_statuses_for_project", R"(
        project_id integer,
        status_id integer
    )");

  addTable("enabled_modules", R"(
        id integer NOT_NULL,
        project_id integer,
        name character_varying NOT_NULL
    )");

  addTable("enterprise_tokens", R"(
        id integer NOT_NULL,
        encoded_token text,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("enumerations", R"(
        id integer NOT_NULL,
        name character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        "position" integer DEFAULT=1,
        is_DEFAULT=boolean DEFAULT=false NOT_NULL,
        type character_varying,
        active boolean DEFAULT=true NOT_NULL,
        project_id integer,
        parent_id integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        color_id integer
    )");

  addTable("export_card_configurations", R"(
        id integer NOT_NULL,
        name character_varying,
        per_page integer,
        page_size character_varying,
        orientation character_varying,
        rows text,
        active boolean DEFAULT=true,
        description text
    )");

  addTable("forums", R"(
        id integer NOT_NULL,
        project_id integer NOT_NULL,
        name character_varying DEFAULT=''::character_varying NOT_NULL,
        description character_varying,
        "position" integer DEFAULT=1,
        topics_count integer DEFAULT=0 NOT_NULL,
        messages_count integer DEFAULT=0 NOT_NULL,
        last_message_id integer
    )");

  addTable("grid_widgets", R"(
        id bigint NOT_NULL,
        start_row integer NOT_NULL,
        end_row integer NOT_NULL,
        start_column integer NOT_NULL,
        end_column integer NOT_NULL,
        identifier character_varying,
        options text,
        grid_id bigint
    )");

  addTable("grids", R"(
        id bigint NOT_NULL,
        row_count integer NOT_NULL,
        column_count integer NOT_NULL,
        type character_varying,
        user_id bigint,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        project_id bigint,
        name text,
        options text
    )");

  addTable("group_users", R"(
        group_id integer NOT_NULL,
        user_id integer NOT_NULL
    )");

  addTable("journal_versions", R"(
        id bigint NOT_NULL,
        journable_type character_varying,
        journable_id integer,
        version integer DEFAULT=0
    )");

  addTable("journals", R"(
        id integer NOT_NULL,
        journable_type character_varying,
        journable_id integer,
        user_id integer DEFAULT=0 NOT_NULL,
        notes text,
        created_at timestamp_without_time_zone NOT_NULL,
        version integer DEFAULT=0 NOT_NULL,
        activity_type character_varying
    )");

  addTable("labor_budget_items", R"(
        id integer NOT_NULL,
        cost_object_id integer NOT_NULL,
        hours double precision NOT_NULL,
        user_id integer,
        comments character_varying DEFAULT=''::character_varying NOT_NULL,
        budget numeric(15,4)
    )");

  addTable("ldap_groups_memberships", R"(
        id integer NOT_NULL,
        user_id integer,
        group_id integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("ldap_groups_synchronized_groups", R"(
        id integer NOT_NULL,
        entry character_varying,
        group_id integer,
        auth_source_id integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("material_budget_items", R"(
        id integer NOT_NULL,
        cost_object_id integer NOT_NULL,
        units double precision NOT_NULL,
        cost_type_id integer,
        comments character_varying DEFAULT=''::character_varying NOT_NULL,
        budget numeric(15,4)
    )");

  addTable("meeting_content_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        meeting_id integer,
        author_id integer,
        text text,
        locked boolean
    )");

  addTable("meeting_contents", R"(
        id integer NOT_NULL,
        type character_varying,
        meeting_id integer,
        author_id integer,
        text text,
        lock_version integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        locked boolean DEFAULT=false
    )");

  addTable("meeting_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        title character_varying,
        author_id integer,
        project_id integer,
        location character_varying,
        start_time timestamp_without_time_zone,
        duration double precision
    )");

  addTable("meeting_participants", R"(
        id integer NOT_NULL,
        user_id integer,
        meeting_id integer,
        email character_varying,
        name character_varying,
        invited boolean,
        attended boolean,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("meetings", R"(
        id integer NOT_NULL,
        title character_varying,
        author_id integer,
        project_id integer,
        location character_varying,
        start_time timestamp_without_time_zone,
        duration double precision,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("member_roles", R"(
        id integer NOT_NULL,
        member_id integer NOT_NULL,
        role_id integer NOT_NULL,
        inherited_from integer
    )");

  addTable("members", R"(
        id integer NOT_NULL,
        user_id integer DEFAULT=0 NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL,
        created_on timestamp_without_time_zone,
        mail_notification boolean DEFAULT=false NOT_NULL
    )");

  addTable("menu_items", R"(
        id integer NOT_NULL,
        name character_varying,
        title character_varying,
        parent_id integer,
        options text,
        navigatable_id integer,
        type character_varying
    )");

  addTable("message_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        forum_id integer NOT_NULL,
        parent_id integer,
        subject character_varying DEFAULT=''::character_varying NOT_NULL,
        content text,
        author_id integer,
        replies_count integer DEFAULT=0 NOT_NULL,
        last_reply_id integer,
        locked boolean DEFAULT=false,
        sticky integer DEFAULT=0
    )");

  addTable("messages", R"(
        id integer NOT_NULL,
        forum_id integer NOT_NULL,
        parent_id integer,
        subject character_varying DEFAULT=''::character_varying NOT_NULL,
        content text,
        author_id integer,
        replies_count integer DEFAULT=0 NOT_NULL,
        last_reply_id integer,
        created_on timestamp_without_time_zone NOT_NULL,
        updated_on timestamp_without_time_zone NOT_NULL,
        locked boolean DEFAULT=false,
        sticky integer DEFAULT=0,
        sticked_on timestamp_without_time_zone
    )");

  addTable("news", R"(
        id integer NOT_NULL,
        project_id integer,
        title character_varying(60) DEFAULT=''::character_varying NOT_NULL,
        summary character_varying DEFAULT=''::character_varying,
        description text,
        author_id integer DEFAULT=0 NOT_NULL,
        created_on timestamp_without_time_zone,
        comments_count integer DEFAULT=0 NOT_NULL
    )");

  addTable("news_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        project_id integer,
        title character_varying(60) DEFAULT=''::character_varying NOT_NULL,
        summary character_varying DEFAULT=''::character_varying,
        description text,
        author_id integer DEFAULT=0 NOT_NULL,
        comments_count integer DEFAULT=0 NOT_NULL
    )");

  addTable("oauth_access_grants", R"(
        id bigint NOT_NULL,
        resource_owner_id bigint NOT_NULL,
        application_id bigint NOT_NULL,
        token character_varying NOT_NULL,
        expires_in integer NOT_NULL,
        redirect_uri text NOT_NULL,
        created_at timestamp_without_time_zone NOT_NULL,
        revoked_at timestamp_without_time_zone,
        scopes character_varying,
        code_challenge character_varying,
        code_challenge_method character_varying
    )");

  addTable("oauth_access_tokens", R"(
        id bigint NOT_NULL,
        resource_owner_id bigint,
        application_id bigint,
        token character_varying NOT_NULL,
        refresh_token character_varying,
        expires_in integer,
        revoked_at timestamp_without_time_zone,
        created_at timestamp_without_time_zone NOT_NULL,
        scopes character_varying,
        previous_refresh_token character_varying DEFAULT=''::character_varying NOT_NULL
    )");

  addTable("oauth_applications", R"(
        id bigint NOT_NULL,
        name character_varying NOT_NULL,
        uid character_varying NOT_NULL,
        secret character_varying NOT_NULL,
        owner_type character_varying,
        owner_id integer,
        client_credentials_user_id integer,
        redirect_uri text NOT_NULL,
        scopes character_varying DEFAULT=''::character_varying NOT_NULL,
        confidential boolean DEFAULT=true NOT_NULL,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("ordered_work_packages", R"(
        id bigint NOT_NULL,
        "position" integer NOT_NULL,
        query_id integer,
        work_package_id integer
    )");

  addTable("plaintext_tokens", R"(
        id integer NOT_NULL,
        user_id integer DEFAULT=0 NOT_NULL,
        action character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        value character_varying(40) DEFAULT=''::character_varying NOT_NULL,
        created_on timestamp_without_time_zone NOT_NULL
    )");

  addTable("principal_roles", R"(
        id integer NOT_NULL,
        role_id integer NOT_NULL,
        principal_id integer NOT_NULL,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("project_associations", R"(
        id integer NOT_NULL,
        project_a_id integer,
        project_b_id integer,
        description text,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone
    )");

  addTable("projects", R"(
        id integer NOT_NULL,
        name character_varying DEFAULT=''::character_varying NOT_NULL,
        description text,
        is_public boolean DEFAULT=true NOT_NULL,
        parent_id integer,
        created_on timestamp_without_time_zone,
        updated_on timestamp_without_time_zone,
        identifier character_varying,
        status integer DEFAULT=1 NOT_NULL,
        lft integer,
        rgt integer
    )");

  addTable("projects_types", R"(
        project_id integer DEFAULT=0 NOT_NULL,
        type_id integer DEFAULT=0 NOT_NULL
    )");

  addTable("queries", R"(
        id integer NOT_NULL,
        project_id integer,
        name character_varying DEFAULT=''::character_varying NOT_NULL,
        filters text,
        user_id integer DEFAULT=0 NOT_NULL,
        is_public boolean DEFAULT=false NOT_NULL,
        column_names text,
        sort_criteria text,
        group_by character_varying,
        display_sums boolean DEFAULT=false NOT_NULL,
        timeline_visible boolean DEFAULT=false,
        show_hierarchies boolean DEFAULT=false,
        timeline_zoom_level integer DEFAULT=5,
        timeline_labels text,
        highlighting_mode text,
        highlighted_attributes text,
        hidden boolean DEFAULT=false,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone,
        display_representation text
    )");

  addTable("rates", R"(
        id integer NOT_NULL,
        valid_from date NOT_NULL,
        rate numeric(15,4) NOT_NULL,
        type character_varying NOT_NULL,
        project_id integer,
        user_id integer,
        cost_type_id integer
    )");

  addTable("recaptcha_entries", R"(
        id integer NOT_NULL,
        user_id bigint,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        version integer NOT_NULL
    )");

  addTable("relations", R"(
        id integer NOT_NULL,
        from_id integer NOT_NULL,
        to_id integer NOT_NULL,
        delay integer,
        description text,
        hierarchy integer DEFAULT=0 NOT_NULL,
        relates integer DEFAULT=0 NOT_NULL,
        duplicates integer DEFAULT=0 NOT_NULL,
        blocks integer DEFAULT=0 NOT_NULL,
        follows integer DEFAULT=0 NOT_NULL,
        includes integer DEFAULT=0 NOT_NULL,
        requires integer DEFAULT=0 NOT_NULL,
        count integer DEFAULT=0 NOT_NULL
    )");

  addTable("repositories", R"(
        id integer NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL,
        url character_varying DEFAULT=''::character_varying NOT_NULL,
        login character_varying(60) DEFAULT=''::character_varying,
        password character_varying DEFAULT=''::character_varying,
        root_url character_varying DEFAULT=''::character_varying,
        type character_varying,
        path_encoding character_varying(64),
        log_encoding character_varying(64),
        scm_type character_varying NOT_NULL,
        required_storage_bytes bigint DEFAULT=0 NOT_NULL,
        storage_updated_at timestamp_without_time_zone
    )");

  addTable("role_permissions", R"(
        id integer NOT_NULL,
        permission character_varying,
        role_id integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("roles", R"(
        id integer NOT_NULL,
        name character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        "position" integer DEFAULT=1,
        assignable boolean DEFAULT=true,
        builtin integer DEFAULT=0 NOT_NULL,
        type character_varying(30) DEFAULT='Role'::character_varying
    )");

  addTable("schema_migrations", R"(
        version character_varying NOT_NULL
    )");

  addTable("sessions", R"(
        id integer NOT_NULL,
        session_id character_varying NOT_NULL,
        data text,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone,
        user_id integer
    )");

  addTable("settings", R"(
        id integer NOT_NULL,
        name character_varying DEFAULT=''::character_varying NOT_NULL,
        value text,
        updated_on timestamp_without_time_zone
    )");

  addTable("statuses", R"(
        id integer NOT_NULL,
        name character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        is_closed boolean DEFAULT=false NOT_NULL,
        is_DEFAULT=boolean DEFAULT=false NOT_NULL,
        "position" integer DEFAULT=1,
        default_done_ratio integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        color_id integer,
        is_readonly boolean DEFAULT=false
    )");

  addTable("time_entries", R"(
        id integer NOT_NULL,
        project_id integer NOT_NULL,
        user_id integer NOT_NULL,
        work_package_id integer,
        hours double precision NOT_NULL,
        comments character_varying,
        activity_id integer NOT_NULL,
        spent_on date NOT_NULL,
        tyear integer NOT_NULL,
        tmonth integer NOT_NULL,
        tweek integer NOT_NULL,
        created_on timestamp_without_time_zone NOT_NULL,
        updated_on timestamp_without_time_zone NOT_NULL,
        overridden_costs numeric(15,4),
        costs numeric(15,4),
        rate_id integer
    )");

  addTable("time_entry_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        project_id integer NOT_NULL,
        user_id integer NOT_NULL,
        work_package_id integer,
        hours double precision NOT_NULL,
        comments character_varying,
        activity_id integer NOT_NULL,
        spent_on date NOT_NULL,
        tyear integer NOT_NULL,
        tmonth integer NOT_NULL,
        tweek integer NOT_NULL,
        overridden_costs numeric(15,2),
        costs numeric(15,2),
        rate_id integer
    )");

  addTable("tokens", R"(
        id integer NOT_NULL,
        user_id bigint,
        type character_varying,
        value character_varying(128) DEFAULT=''::character_varying NOT_NULL,
        created_on timestamp_without_time_zone NOT_NULL,
        expires_on timestamp_without_time_zone
    )");

  addTable("two_factor_authentication_devices", R"(
        id integer NOT_NULL,
        type character_varying,
        "default" boolean DEFAULT=false NOT_NULL,
        active boolean DEFAULT=false NOT_NULL,
        channel character_varying NOT_NULL,
        phone_number character_varying,
        identifier character_varying NOT_NULL,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        last_used_at integer,
        otp_secret text,
        user_id integer
    )");

  addTable("types", R"(
        id integer NOT_NULL,
        name character_varying DEFAULT=''::character_varying NOT_NULL,
        "position" integer DEFAULT=1,
        is_in_roadmap boolean DEFAULT=true NOT_NULL,
        is_milestone boolean DEFAULT=false NOT_NULL,
        is_DEFAULT=boolean DEFAULT=false NOT_NULL,
        color_id integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL,
        is_standard boolean DEFAULT=false NOT_NULL,
        attribute_groups text,
        description text
    )");

  addTable("user_passwords", R"(
        id integer NOT_NULL,
        user_id integer NOT_NULL,
        hashed_password character_varying(128) NOT_NULL,
        salt character_varying(64),
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone,
        type character_varying NOT_NULL
    )");

  addTable("user_preferences", R"(
        id integer NOT_NULL,
        user_id integer DEFAULT=0 NOT_NULL,
        others text,
        hide_mail boolean DEFAULT=true,
        time_zone character_varying
    )");

  addTable("users", R"(
        id integer NOT_NULL,
        login character_varying(256) DEFAULT=''::character_varying NOT_NULL,
        firstname character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        lastname character_varying(30) DEFAULT=''::character_varying NOT_NULL,
        mail character_varying(60) DEFAULT=''::character_varying NOT_NULL,
        admin boolean DEFAULT=false NOT_NULL,
        status integer DEFAULT=1 NOT_NULL,
        last_login_on timestamp_without_time_zone,
        language character_varying(5) DEFAULT=''::character_varying,
        auth_source_id integer,
        created_on timestamp_without_time_zone,
        updated_on timestamp_without_time_zone,
        type character_varying,
        identity_url character_varying,
        mail_notification character_varying DEFAULT=''::character_varying NOT_NULL,
        first_login boolean DEFAULT=true NOT_NULL,
        force_password_change boolean DEFAULT=false,
        failed_login_count integer DEFAULT=0,
        last_failed_login_on timestamp_without_time_zone,
        consented_at timestamp_without_time_zone
    )");

  addTable("version_settings", R"(
        id integer NOT_NULL,
        project_id integer,
        version_id integer,
        display integer,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("versions", R"(
        id integer NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL,
        name character_varying DEFAULT=''::character_varying NOT_NULL,
        description character_varying DEFAULT=''::character_varying,
        effective_date date,
        created_on timestamp_without_time_zone,
        updated_on timestamp_without_time_zone,
        wiki_page_title character_varying,
        status character_varying DEFAULT='open'::character_varying,
        sharing character_varying DEFAULT='none'::character_varying NOT_NULL,
        start_date date
    )");

  addTable("watchers", R"(
        id integer NOT_NULL,
        watchable_type character_varying DEFAULT=''::character_varying NOT_NULL,
        watchable_id integer DEFAULT=0 NOT_NULL,
        user_id integer
    )");

  addTable("webhooks_events", R"(
        id integer NOT_NULL,
        name character_varying,
        webhooks_webhook_id integer
    )");

  addTable("webhooks_logs", R"(
        id integer NOT_NULL,
        webhooks_webhook_id integer,
        event_name character_varying,
        url character_varying,
        request_headers text,
        request_body text,
        response_code integer,
        response_headers text,
        response_body text,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("webhooks_projects", R"(
        id integer NOT_NULL,
        project_id integer,
        webhooks_webhook_id integer
    )");

  addTable("webhooks_webhooks", R"(
        id integer NOT_NULL,
        name character_varying,
        url text,
        description text NOT_NULL,
        secret character_varying,
        enabled boolean NOT_NULL,
        all_projects boolean NOT_NULL,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("wiki_content_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        page_id integer NOT_NULL,
        author_id integer,
        text text
    )");

  addTable("wiki_contents", R"(
        id integer NOT_NULL,
        page_id integer NOT_NULL,
        author_id integer,
        text text,
        updated_on timestamp_without_time_zone NOT_NULL,
        lock_version integer NOT_NULL
    )");

  addTable("wiki_pages", R"(
        id integer NOT_NULL,
        wiki_id integer NOT_NULL,
        title character_varying NOT_NULL,
        created_on timestamp_without_time_zone NOT_NULL,
        protected boolean DEFAULT=false NOT_NULL,
        parent_id integer,
        slug character_varying NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("wiki_redirects", R"(
        id integer NOT_NULL,
        wiki_id integer NOT_NULL,
        title character_varying,
        redirects_to character_varying,
        created_on timestamp_without_time_zone NOT_NULL
    )");

  addTable("wikis", R"(
        id integer NOT_NULL,
        project_id integer NOT_NULL,
        start_page character_varying NOT_NULL,
        status integer DEFAULT=1 NOT_NULL,
        created_at timestamp_without_time_zone NOT_NULL,
        updated_at timestamp_without_time_zone NOT_NULL
    )");

  addTable("work_package_journals", R"(
        id integer NOT_NULL,
        journal_id integer NOT_NULL,
        type_id integer DEFAULT=0 NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL,
        subject character_varying DEFAULT=''::character_varying NOT_NULL,
        description text,
        due_date date,
        category_id integer,
        status_id integer DEFAULT=0 NOT_NULL,
        assigned_to_id integer,
        priority_id integer DEFAULT=0 NOT_NULL,
        fixed_version_id integer,
        author_id integer DEFAULT=0 NOT_NULL,
        done_ratio integer DEFAULT=0 NOT_NULL,
        estimated_hours double precision,
        start_date date,
        parent_id integer,
        responsible_id integer,
        cost_object_id integer,
        story_points integer,
        remaining_hours double precision,
        derived_estimated_hours double precision
    )");

  addTable("work_packages", R"(
        id integer NOT_NULL,
        type_id integer DEFAULT=0 NOT_NULL,
        project_id integer DEFAULT=0 NOT_NULL,
        subject character_varying DEFAULT=''::character_varying NOT_NULL,
        description text,
        due_date date,
        category_id integer,
        status_id integer DEFAULT=0 NOT_NULL,
        assigned_to_id integer,
        priority_id integer DEFAULT=0,
        fixed_version_id integer,
        author_id integer DEFAULT=0 NOT_NULL,
        lock_version integer DEFAULT=0 NOT_NULL,
        done_ratio integer DEFAULT=0 NOT_NULL,
        estimated_hours double precision,
        created_at timestamp_without_time_zone,
        updated_at timestamp_without_time_zone,
        start_date date,
        responsible_id integer,
        cost_object_id integer,
        "position" integer,
        story_points integer,
        remaining_hours double precision,
        derived_estimated_hours double precision
    )");

  addTable("workflows", R"(
        id integer NOT_NULL,
        type_id integer DEFAULT=0 NOT_NULL,
        old_status_id integer DEFAULT=0 NOT_NULL,
        new_status_id integer DEFAULT=0 NOT_NULL,
        role_id integer DEFAULT=0 NOT_NULL,
        assignee boolean DEFAULT=false NOT_NULL,
        author boolean DEFAULT=false NOT_NULL
    )");
}
}  // namespace widgets
