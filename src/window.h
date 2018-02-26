#pragma once

#include <QMainWindow>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QListWidget>
#include <QStackedWidget>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QSpinBox>
#include <QComboBox>
#include <QSlider>
#include <QTimer>
#include <QFileDialog>
#include <QCoreApplication>

#include "src/pvz.h"

class MainWindow : public QWidget
{
  Q_OBJECT

public:
  MainWindow();
  MainWindow(MainWindow &&) = delete;
  MainWindow(const MainWindow &) = delete;
  MainWindow &operator=(MainWindow &&) = delete;
  MainWindow &operator=(const MainWindow &) = delete;
  ~MainWindow();

signals:
  void UnpackPAK(QString, QString);
  void PackPAK(QString);

public slots:
  void FindResult(int);

private:
  // String List
  QStringList list_menu;
  QStringList list_adventure;
  QStringList list_minigames;
  QStringList list_puzzle;
  QStringList list_survival;
  QStringList list_slots_index;
  QStringList list_slots_seed;
  QStringList list_zombie;
  QStringList list_game_scene;
  QStringList list_projectile;
  QStringList list_zombie_status;
  QStringList list_rows;
  // Worker/Thread
  PVZ *pvz;
  QThread *thread;
  // Main Widget/Layout
  QListWidget *list_widget;
  QStackedWidget *stacked_widget;
  QHBoxLayout *main_layout;
  // Page 0 : Resources
  QWidget *page_resources;
  QGridLayout *layout_resources;
  QTimer *timer_coin_disappear;
  QLabel *label_sun;
  QLineEdit *line_edit_sun;
  QPushButton *push_button_sun;
  QCheckBox *check_box_sun_limit;
  QLabel *label_money;
  QLineEdit *line_edit_money;
  QPushButton *push_button_money;
  QCheckBox *check_box_money_limit;
  QCheckBox *check_box_many_falling_sun;
  QCheckBox *check_box_no_falling_sun;
  QCheckBox *check_box_auto_collect;
  QCheckBox *check_box_coin_disappear;
  QLabel *label_height;
  QLineEdit *line_edit_height;
  QPushButton *push_button_height;
  QPushButton *push_button_all_shop_items;
  QCheckBox *check_box_fertilizer_unlimited;
  QCheckBox *check_box_bug_spray_unlimited;
  QCheckBox *check_box_chocolate_unlimited;
  QCheckBox *check_box_tree_food_unlimited;
  // Page 1 : Level
  QWidget *page_level;
  QGridLayout *layout_level;
  QPushButton *push_button_gold_sunflower_trophy;
  QCheckBox *check_box_unlock_all_mode;
  QCheckBox *check_box_show_hide_games;
  QPushButton *push_button_win;
  QLabel *label_endless;
  QLineEdit *line_edit_level;
  QPushButton *push_button_jump_level;
  QComboBox *combo_box_mixmode_menu;
  QComboBox *combo_box_mixmode_adventure;
  QComboBox *combo_box_mixmode_minigames;
  QComboBox *combo_box_mixmode_puzzle;
  QComboBox *combo_box_mixmode_survival;
  QStackedWidget *stacked_widget_mixmode_choose;
  QPushButton *push_button_mixmode;
  QLabel *label_scene_type;
  QComboBox *combo_box_scene_type;
  QPushButton *push_button_scene_type;
  QLabel *label_fc_caution;
  // Page 2 : Plants
  QWidget *page_plant;
  QGridLayout *layout_plant;
  QCheckBox *check_box_cob_cannon_nocd;
  QCheckBox *check_box_magnets_nocd;
  QCheckBox *check_box_potato_mine_nocd;
  QCheckBox *check_box_chomper_nocd;
  QCheckBox *check_box_plant_invincible;
  QCheckBox *check_box_plant_weak;
  QCheckBox *check_box_lock_kernel;
  QCheckBox *check_box_lock_butter;
  QCheckBox *check_box_no_crater;
  QCheckBox *check_box_mushrooms_awake;
  QCheckBox *check_box_strong_blover;
  QCheckBox *check_box_strong_peas;
  QCheckBox *check_box_umbrella;
  QCheckBox *check_box_beghouled_free_move;
  QCheckBox *check_box_produce_speed_up;
  QCheckBox *check_box_attack_speed_up;
  QLabel *label_plant_damage;
  QComboBox *combo_box_plant_projectile;
  QLineEdit *line_edit_plant_damage;
  QPushButton *push_button_plant_damage;
  // Page 3 : Zombies
  QWidget *page_zombie;
  QGridLayout *layout_zombie;
  QCheckBox *check_box_zombie_explode_immediately;
  QCheckBox *check_box_zombie_explode_never;
  QCheckBox *check_box_zombie_invisible;
  QCheckBox *check_box_zombie_show;
  QCheckBox *check_box_zombie_weak;
  QCheckBox *check_box_zombie_invincible;
  QCheckBox *check_box_stop_spawning;
  QCheckBox *check_box_zombies_no_move;
  QCheckBox *check_box_no_ice_slow_down;
  QCheckBox *check_box_no_butter_immobilize;
  QCheckBox *check_box_no_3_zombies_group;
  QCheckBox *check_box_no_ice_trail;
  QCheckBox *check_box_no_throw_imp;
  QCheckBox *check_box_gargantuar_eatable;
  QCheckBox *check_box_zomboss_no_move;
  QCheckBox *check_box_balloon_burst;
  QCheckBox *check_box_gather_zombies;
  QSlider *slider_gather_zombies;
  QPushButton *push_button_spawning_all_zombies;
  QLabel *label_all_zombies;
  QComboBox *combo_box_all_zombies;
  QPushButton *push_button_all_zombies;
  // Page 4 : Spawn
  QWidget *page_spawn;
  QGridLayout *layout_spawn;
  QWidget *widget_spawn_brief;
  QGridLayout *layout_spawn_brief;
  QCheckBox *check_box_spawn_2, *check_box_spawn_3, *check_box_spawn_4, *check_box_spawn_5, *check_box_spawn_6,
      *check_box_spawn_7, *check_box_spawn_8, *check_box_spawn_11, *check_box_spawn_12, *check_box_spawn_14,
      *check_box_spawn_15, *check_box_spawn_16, *check_box_spawn_17, *check_box_spawn_18, *check_box_spawn_19,
      *check_box_spawn_20, *check_box_spawn_21, *check_box_spawn_22, *check_box_spawn_23, *check_box_spawn_32;
  QPushButton *push_button_natural_spawn;
  QPushButton *push_button_extreme_spawn;
  QCheckBox *check_box_detailed_mode;
  QLineEdit *line_edit_random_seed;
  QPushButton *push_button_random_seed;
  QComboBox *combo_box_spawn_menu;
  QPushButton *push_button_spawn_add;
  QPushButton *push_button_spawn_delete;
  QPushButton *push_button_spawn_clear;
  QRadioButton *radio_button_natural_spawn;
  QRadioButton *radio_button_extreme_spawn;
  QCheckBox *check_box_evenly_filled;
  QCheckBox *check_box_limit_yeti;
  QCheckBox *check_box_limit_bungee;
  QCheckBox *check_box_limit_giga;
  QPushButton *push_button_spawn_original;
  QPushButton *push_button_spawn_set;
  QListWidget *list_widget_spawn;
  QSpacerItem *spacer_spawn_0, *spacer_spawn_1, *spacer_spawn_2, *spacer_spawn_3;
  // Page 5 : Slots
  QWidget *page_slots;
  QGridLayout *layout_slots;
  QLabel *label_slots_count;
  QSpinBox *spin_box_slots_count;
  QPushButton *push_button_slots_count;
  QPushButton *push_button_show_shovel;
  QComboBox *combo_box_slots_slot;
  QComboBox *combo_box_slots_seed;
  QPushButton *push_button_slots_set;
  QCheckBox *check_box_slots_imitater;
  QCheckBox *check_box_slots_belt_no_delay;
  QCheckBox *check_box_slots_purple_seed_unlimited;
  QCheckBox *check_box_planting_freely;
  QCheckBox *check_box_lock_shovel;
  QComboBox *combo_box_seed;
  QCheckBox *check_box_ignore_sun;
  QCheckBox *check_box_slots_no_cool_down;
  QLabel *label_seed_speed;
  QLineEdit *line_edit_seed_speed;
  QPushButton *push_button_seed_speed;
  QLabel *label_seed_cost;
  QLineEdit *line_edit_seed_cost;
  QPushButton *push_button_seed_cost;
  QLabel *label_seed_recharge;
  QLineEdit *line_edit_seed_recharge;
  QPushButton *push_button_seed_recharge;
  // Page 6 : Scene
  QWidget *page_scene;
  QGridLayout *layout_scene;
  QLabel *label_scene_row;
  QLabel *label_scene_col;
  QSpinBox *spin_box_scene_row;
  QSpinBox *spin_box_scene_col;
  QComboBox *combo_box_plant_menu;
  QPushButton *push_button_put_plant;
  QCheckBox *check_box_plant_imitater;
  QComboBox *combo_box_zombie_menu;
  QPushButton *push_button_put_zombie;
  QPushButton *push_button_put_grave;
  QPushButton *push_button_put_ladder;
  QPushButton *push_button_auto_ladder;
  QCheckBox *check_box_imitater_pumpkin_only;
  QPushButton *push_button_eat_all_graves;
  QPushButton *push_button_lily_pad_on_pool;
  QPushButton *push_button_flower_pot_on_roof;
  QPushButton *push_button_clear_all_plants;
  QLabel *label_block_type;
  QComboBox *combo_box_block_type;
  QPushButton *push_button_block_type;
  QComboBox *combo_box_scene_row;
  QComboBox *combo_box_row_type;
  QPushButton *push_button_row_type;
  QPushButton *push_button_start_lawn_mowers;
  QPushButton *push_button_reset_lawn_mowers;
  // Page 7 : Effects
  QWidget *page_effects;
  QGridLayout *layout_effects;
  QPushButton *push_button_code_sukhbir;
  QPushButton *push_button_code_future;
  QPushButton *push_button_code_mustache;
  QPushButton *push_button_code_trickedout;
  QPushButton *push_button_code_daisies;
  QPushButton *push_button_code_dance;
  QPushButton *push_button_code_pinata;
  QPushButton *push_button_code_konami;
  QCheckBox *check_box_effect_little_zombie;
  QCheckBox *check_box_effect_its_raining;
  QCheckBox *check_box_effect_stormy_night;
  QCheckBox *check_box_effect_high_gravity;
  QCheckBox *check_box_effect_column_like;
  QCheckBox *check_box_effect_zombie_quick;
  QLabel *label_ice_trail_x;
  QComboBox *combo_box_ice_trail_x;
  QLineEdit *line_edit_ice_trail_x;
  QPushButton *push_button_ice_trail_x;
  QCheckBox *check_box_full_fog;
  QCheckBox *check_box_no_fog;
  QCheckBox *check_box_see_vase;
  // Page 8 : Others
  QWidget *page_others;
  QGridLayout *layout_others;
  QCheckBox *check_box_disable_save_data;
  QCheckBox *check_box_disable_delete_data;
  QCheckBox *check_box_running_in_background;
  QCheckBox *check_box_no_pause;
  QLabel *label_debug_mode;
  QComboBox *combo_box_debug_mode_menu;
  QPushButton *push_button_debug_mode;
  QPushButton *push_button_pak_file;
  QLineEdit *line_edit_pak_file;
  QPushButton *push_button_pak_unpack;
  QPushButton *push_button_pak_dir;
  QLineEdit *line_edit_pak_dir;
  QPushButton *push_button_pak_pack;
  // Page 9 : Status
  QWidget *page_status;
  QGridLayout *layout_status;
  QTimer *timer_status_refresh;
  QLabel *label_game_mode_text;
  QCheckBox *check_box_auto_refresh;
  QSpinBox *spin_box_refresh_interval;
  QLabel *label_game_mode;
  QLabel *label_game_mode_value;
  QLabel *label_game_ui;
  QLabel *label_game_ui_value;
  QLabel *label_running_time;
  QLabel *label_running_time_value;
  QLabel *label_level_completed;
  QLabel *label_level_completed_value;
  QLabel *label_total_waves;
  QLabel *label_total_waves_value;
  QLabel *label_past_waves;
  QLabel *label_past_waves_value;
  QLabel *label_total_hp;
  QLabel *label_total_hp_value;
  QLabel *label_trigger_hp;
  QLabel *label_trigger_hp_value;
  QLabel *label_countdown;
  QLabel *label_countdown_value;
  QLabel *label_hugewave_countdown;
  QLabel *label_hugewave_countdown_value;
  QLabel *label_plant_count;
  QLabel *label_plant_count_value;
  QLabel *label_zombie_count;
  QLabel *label_zombie_count_value;
  // Page 10 : About
  QWidget *page_about;
  QGridLayout *layout_about;
  QLabel *label_logo;
  QLabel *label_name;
  QLabel *label_version;
  QLabel *label_copy;
  QLabel *label_license;
  QLabel *label_contact;
  QLabel *label_website;
  QPushButton *push_button_find_game;
};
