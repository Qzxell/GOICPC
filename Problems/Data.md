---

database-plugin: basic

---

```yaml:dbfolder
name: new database
description: new description
columns:
  __file__:
    key: __file__
    id: __file__
    input: markdown
    label: File
    accessorKey: __file__
    isMetadata: true
    skipPersist: false
    isDragDisabled: false
    csvCandidate: true
    position: 1
    isHidden: false
    sortIndex: -1
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: true
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  tags:
    input: tags
    accessorKey: tags
    key: tags
    id: tags
    label: tags
    position: 2
    skipPersist: false
    isHidden: false
    sortIndex: -1
    width: 207
    options:
      - { label: "asdf", value: "asdf", color: "hsl(167, 95%, 90%)"}
      - { label: "asds", value: "asds", color: "hsl(120, 95%, 90%)"}
      - { label: "combinatorics", value: "combinatorics", color: "hsl(239, 95%, 90%)"}
      - { label: "1200", value: "1200", color: "hsl(98, 95%, 90%)"}
      - { label: "atcoder", value: "atcoder", color: "hsl(329, 95%, 90%)"}
      - { label: "math", value: "math", color: "hsl(95, 95%, 90%)"}
      - { label: "implementation", value: "implementation", color: "hsl(316, 95%, 90%)"}
      - { label: "constructive algorithm", value: "constructive algorithm", color: "hsl(72, 95%, 90%)"}
      - { label: "force brute", value: "force brute", color: "hsl(307, 95%, 90%)"}
      - { label: "greedy", value: "greedy", color: "hsl(87, 95%, 90%)"}
      - { label: "bitmask", value: "bitmask", color: "hsl(195, 95%, 90%)"}
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  Level:
    input: number
    accessorKey: Level
    key: Level
    id: Level
    label: Level
    position: 4
    skipPersist: false
    isHidden: false
    sortIndex: -1
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  Idea_clave:
    input: text
    accessorKey: Idea_clave
    key: Idea_clave
    id: Idea_clave
    label: Idea clave
    position: 5
    skipPersist: false
    isHidden: false
    sortIndex: -1
    width: 263
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  MIstakes:
    input: text
    accessorKey: MIstakes
    key: MIstakes
    id: MIstakes
    label: Mistakes
    position: 6
    skipPersist: false
    isHidden: false
    sortIndex: -1
    width: 207
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  Solved:
    input: checkbox
    accessorKey: Solved
    key: Solved
    id: Solved
    label: Solved
    position: 3
    skipPersist: false
    isHidden: false
    sortIndex: -1
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  resolve_again_obligatory:
    input: checkbox
    accessorKey: resolve_again_obligatory
    key: resolve_again_obligatory
    id: resolve_again_obligatory
    label: resolve again obligatory
    position: 100
    skipPersist: false
    isHidden: false
    sortIndex: -1
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
  URL:
    input: text
    accessorKey: URL
    key: URL
    id: URL
    label: URL
    position: 100
    skipPersist: false
    isHidden: false
    sortIndex: -1
    config:
      enable_media_view: true
      link_alias_enabled: true
      media_width: 100
      media_height: 100
      isInline: false
      task_hide_completed: true
      footer_type: none
      persist_changes: false
config:
  remove_field_when_delete_column: false
  cell_size: normal
  sticky_first_column: false
  group_folder_column: 
  remove_empty_folders: false
  automatically_group_files: false
  hoist_files_with_empty_attributes: true
  show_metadata_created: false
  show_metadata_modified: false
  show_metadata_tasks: false
  show_metadata_inlinks: false
  show_metadata_outlinks: false
  show_metadata_tags: false
  source_data: current_folder
  source_form_result: 
  source_destination_path: /
  row_templates_folder: /
  current_row_template: 
  pagination_size: 10
  font_size: 16
  enable_js_formulas: false
  formula_folder_path: /
  inline_default: false
  inline_new_position: last_field
  date_format: yyyy-MM-dd
  datetime_format: "yyyy-MM-dd HH:mm:ss"
  metadata_date_format: "yyyy-MM-dd HH:mm:ss"
  enable_footer: false
  implementation: default
filters:
  enabled: false
  conditions:
```