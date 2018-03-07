
#include "src/window.h"

MainWindow::MainWindow()
{

    this->list_menu << tr("Adventure")  // 0
                    << tr("Mini-Games") // 16-50
                    << tr("Puzzle")     // 51-72
                    << tr("Survival");  // 1-15

    this->list_adventure << "1-1"
                         << "1-2"
                         << "1-3"
                         << "1-4"
                         << "1-5"
                         << "1-6"
                         << "1-7"
                         << "1-8"
                         << "1-9"
                         << "1-10"
                         << "2-1"
                         << "2-2"
                         << "2-3"
                         << "2-4"
                         << "2-5"
                         << "2-6"
                         << "2-7"
                         << "2-8"
                         << "2-9"
                         << "2-10"
                         << "3-1"
                         << "3-2"
                         << "3-3"
                         << "3-4"
                         << "3-5"
                         << "3-6"
                         << "3-7"
                         << "3-8"
                         << "3-9"
                         << "3-10"
                         << "4-1"
                         << "4-2"
                         << "4-3"
                         << "4-4"
                         << "4-5"
                         << "4-6"
                         << "4-7"
                         << "4-8"
                         << "4-9"
                         << "4-10"
                         << "5-1"
                         << "5-2"
                         << "5-3"
                         << "5-4"
                         << "5-5"
                         << "5-6"
                         << "5-7"
                         << "5-8"
                         << "5-9"
                         << "5-10";

    this->list_minigames << tr("ZomBotany")                  // 16
                         << tr("Wall-nut Bowling")           // 17
                         << tr("Slot Machine")               // 18
                         << tr("It's Raining Seeds")         // 19
                         << tr("Beghouled")                  // 20
                         << tr("Invisi-ghoul")               // 21
                         << tr("Seeing Stars")               // 22
                         << tr("Zombiquarium")               // 23
                         << tr("Beghouled Twist")            // 24
                         << tr("Big Trouble Little Zombie")  // 25
                         << tr("Portal Combat")              // 26
                         << tr("Column Like You See'Em")     // 27
                         << tr("Bobseld Bonanza")            // 28
                         << tr("Zombie Nimble Zombie Quick") // 29
                         << tr("Whack a Zombie")             // 30
                         << tr("Last Stand")                 // 31
                         << tr("ZomBotany 2")                // 32
                         << tr("Wall-nut Bowling 2")         // 33
                         << tr("Pogo Party")                 // 34
                         << tr("Dr. Zomboss's Revenge")      // 35
                         << tr("Art Challenge Wall-nut")     // 36
                         << tr("Sunny Day")                  // 37
                         << tr("Unsodded (FC)")              // 38
                         << tr("Big Time")                   // 39
                         << tr("Art Challenge Sunflower")    // 40
                         << tr("Air Raid")                   // 41
                         << tr("Ice Level")                  // 42
                         << tr("Zen Garden (FC)")            // 43
                         << tr("High Gravity")               // 44
                         << tr("Grave Danger")               // 45
                         << tr("Can You Dig It?")            // 46
                         << tr("Dark Stormy Night")          // 47
                         << tr("Bungee Blitz")               // 48
                         << tr("Squirrel")                   // 49
                         << tr("Tree of Wisdom");            // 50

    this->list_puzzle << tr("Vasebreaker")                    // 51
                      << tr("To the Left")                    // 52
                      << tr("Third Vase")                     // 53
                      << tr("Chain Reaction")                 // 54
                      << tr("M is for Metal")                 // 55
                      << tr("Scary Potter")                   // 56
                      << tr("Hokey Pokey")                    // 57
                      << tr("Another Chain Reaction")         // 58
                      << tr("Ace of Vase")                    // 59
                      << tr("Vasebreaker Endless")            // 60
                      << tr("I, Zombie")                      // 61
                      << tr("I, Zombie Too")                  // 62
                      << tr("Can You Dig It?")                // 63
                      << tr("Totally Nuts")                   // 64
                      << tr("Dead Zeppelin")                  // 65
                      << tr("Me Smash!")                      // 66
                      << tr("ZomBoogie")                      // 67
                      << tr("Three Hit Wonder")               // 68
                      << tr("All your brainz r belong to us") // 69
                      << tr("I, Zombie Endless")              // 70
                      << tr("Upsell")                         // 71
                      << tr("Intro");                         // 72

    this->list_survival << tr("Survival: Day")             // 1
                        << tr("Survival: Night")           // 2
                        << tr("Survival: Pool")            // 3
                        << tr("Survival: Fog")             // 4
                        << tr("Survival: Roof")            // 5
                        << tr("Survival: Day (Hard)")      // 6
                        << tr("Survival: Night (Hard)")    // 7
                        << tr("Survival: Pool (Hard)")     // 8
                        << tr("Survival: Fog (Hard)")      // 9
                        << tr("Survival: Roof (Hard)")     // 10
                        << tr("Survival: Day (Endless)")   // 11
                        << tr("Survival: Night (Endless)") // 12
                        << tr("Survival: Endless")         // 13
                        << tr("Survival: Fog (Endless)")   // 14
                        << tr("Survival: Roof (Endless)"); // 15

    this->list_slots_index << tr("1st slot")
                           << tr("2nd slot")
                           << tr("3rd slot")
                           << tr("4th slot")
                           << tr("5th slot")
                           << tr("6th slot")
                           << tr("7th slot")
                           << tr("8th slot")
                           << tr("9th slot")
                           << tr("10th slot");

    this->list_slots_seed << tr("Peashooter") // 0
                          << tr("Sunflower")
                          << tr("Cherry Bomb")
                          << tr("Wall-nut")
                          << tr("Potato Mine")
                          << tr("Snow Pea")
                          << tr("Chomper")
                          << tr("Repeater")
                          << tr("Puff-shroom")
                          << tr("Sun-shroom")
                          << tr("Fume-shroom")
                          << tr("Grave Buster")
                          << tr("Hypno-shroom")
                          << tr("Scaredy-shroom")
                          << tr("Ice-shroom")
                          << tr("Doom-shroom")
                          << tr("Lily Pad")
                          << tr("Squash")
                          << tr("Threepeater")
                          << tr("Tangle Kelp")
                          << tr("Jalapeno")
                          << tr("Spikeweed")
                          << tr("Torchwood")
                          << tr("Tall-nut")
                          << tr("Sea-shroom")
                          << tr("Plantern")
                          << tr("Cactus")
                          << tr("Blover")
                          << tr("Split Pea")
                          << tr("Starfruit")
                          << tr("Pumpkin")
                          << tr("Magnet-shroom")
                          << tr("Cabbage-pult")
                          << tr("Flower Pot")
                          << tr("Kernel-pult")
                          << tr("Coffee Bean")
                          << tr("Garlic")
                          << tr("Umbrella Leaf")
                          << tr("Marigold")
                          << tr("Melon-pult")
                          << tr("Gatling Pea")
                          << tr("Twin Sunflower")
                          << tr("Gloom-shroom")
                          << tr("Cattail")
                          << tr("Winter Melon")
                          << tr("Gold Magnet")
                          << tr("Spikerock")
                          << tr("Cob Cannon") // 47
                          << tr("Imitater")   // 48
                          << tr("Explode-o-nut")
                          << tr("Giant Wall-nut")
                          << tr("Sprout")
                          << tr("Reverse Repeater")
                          << tr("Nothing (FC)")       // 53
                          << tr("Shuffle plant (FC)") // 54
                          << tr("Refill crator (FC)") // 55
                          << tr("Sun (FC)")           // 56
                          << tr("Diamond (FC)")       // 57
                          << tr("Snorkel Zombie")
                          << tr("Trophy")
                          << tr("Zombie")
                          << tr("Conehead Zombie")
                          << tr("Pole Vaulting Zombie")
                          << tr("Buckethead Zombie")
                          << tr("Ladder Zombie")
                          << tr("Digger Zombie")
                          << tr("Bungee Zombie")
                          << tr("Football Zombie")
                          << tr("Balloon Zombie")
                          << tr("Screen Door Zombie")
                          << tr("Zomboni")
                          << tr("Pogo Zombie")
                          << tr("Dancing Zombie")
                          << tr("Gargantuar")
                          << tr("Imp")
                          << tr("<Missing> (FC)"); // 75

    this->list_zombie << tr("Zombie")                 // 0
                      << tr("Flag Zombie")            // 1
                      << tr("Conehead Zombie")        // 2
                      << tr("Pole Vaulting Zombie")   // 3
                      << tr("Buckethead Zombie")      // 4
                      << tr("Newspaper Zombie")       // 5
                      << tr("Screen Door Zombie")     // 6
                      << tr("Football Zombie")        // 7
                      << tr("Dancing Zombie")         // 8
                      << tr("Backup Dancer")          // 9
                      << tr("Ducky Tube Zombie")      // 10
                      << tr("Snorkel Zombie")         // 11
                      << tr("Zomboni")                // 12
                      << tr("Zombie Bobsled Team")    // 13
                      << tr("Dolphin Rider Zombie")   // 14
                      << tr("Jack-in-the-Box Zombie") // 15
                      << tr("Balloon Zombie")         // 16
                      << tr("Digger Zombie")          // 17
                      << tr("Pogo Zombie")            // 18
                      << tr("Zombie Yeti")            // 19
                      << tr("Bungee Zombie")          // 20
                      << tr("Ladder Zombie")          // 21
                      << tr("Catapult Zombie")        // 22
                      << tr("Gargantuar")             // 23
                      << tr("Imp")                    // 24
                      << tr("Dr. Zomboss")            // 25
                      << tr("Peashooter Zombie")      // 26
                      << tr("Wall-nut Zombie")        // 27
                      << tr("Jalapeno Zombie")        // 28
                      << tr("Gatling Pea Zombie")     // 29
                      << tr("Squash Zombie")          // 30
                      << tr("Tall-nut Zombie")        // 31
                      << tr("GigaGargantuar");        // 32

    this->list_game_scene << tr("Day")
                          << tr("Night")
                          << tr("Pool")
                          << tr("Fog")
                          << tr("Roof")
                          << tr("Moon")
                          << tr("Mushroom Garden")
                          << tr("Zen Garden")
                          << tr("Aquarium Garden")
                          << tr("Tree of Wisdom");

    this->list_projectile << tr("Pea")
                          << tr("Frozen Pea")
                          << tr("Cabbage")
                          << tr("Melon")
                          << tr("Fume")
                          << tr("Winter Melon")
                          << tr("Fireball")
                          << tr("Star")
                          << tr("Spike")
                          << tr("Basketball")
                          << tr("Kernel")
                          << tr("Unknown")
                          << tr("Butter")
                          << tr("Zombie Pea");

    this->list_zombie_status << tr("Kill")
                             << tr("Hypno")
                             << tr("Freeze")
                             << tr("Decelerate")
                             << tr("Immobilize")
                             << tr("Blow Away")
                             << tr("Dying")
                             << tr("Disappear")
                             << tr("Black")
                             << tr("Bigger");

    this->list_rows << tr("All Rows")
                    << tr("1st Row")
                    << tr("2nd Row")
                    << tr("3rd Row")
                    << tr("4th Row")
                    << tr("5th Row")
                    << tr("6th Row");

    pvz = new PVZ;        // No Parents :-(
    thread = new QThread; // Me Too :-(
    pvz->moveToThread(thread);

    // Main List Widget
    list_widget = new QListWidget(this);
    list_widget->addItem(tr("Resources"));
    list_widget->addItem(tr("Level"));
    list_widget->addItem(tr("Plants"));
    list_widget->addItem(tr("Zombies"));
    list_widget->addItem(tr("Spawn"));
    list_widget->addItem(tr("Slots"));
    list_widget->addItem(tr("Scene"));
    list_widget->addItem(tr("Effects"));
    list_widget->addItem(tr("Others"));
    list_widget->addItem(tr("Status"));
    list_widget->addItem(tr("About"));
    list_widget->setCurrentRow(0);

    // Page 0 : Resources

    page_resources = new QWidget(this);

    timer_coin_disappear = new QTimer(page_resources);
    timer_coin_disappear->setInterval(10);

    label_sun = new QLabel(page_resources);
    label_sun->setText(tr("Sun"));
    line_edit_sun = new QLineEdit(page_resources);
    line_edit_sun->setText("9990");
    line_edit_sun->setValidator(new QIntValidator(0, 999999999, this));
    line_edit_sun->setAlignment(Qt::AlignRight);
    push_button_sun = new QPushButton(page_resources);
    push_button_sun->setText(tr("Set"));
    check_box_sun_limit = new QCheckBox(page_resources);
    check_box_sun_limit->setText(tr("Increase Upper Limit"));

    label_money = new QLabel(page_resources);
    label_money->setText(tr("Money"));
    line_edit_money = new QLineEdit(page_resources);
    line_edit_money->setText("999990");
    line_edit_money->setValidator(new QIntValidator(0, 999999999, this));
    line_edit_money->setAlignment(Qt::AlignRight);
    push_button_money = new QPushButton(page_resources);
    push_button_money->setText(tr("Set"));
    check_box_money_limit = new QCheckBox(page_resources);
    check_box_money_limit->setText(tr("Increase Upper Limit"));

    check_box_many_falling_sun = new QCheckBox(page_resources);
    check_box_many_falling_sun->setText(tr("Many Falling Sun"));
    check_box_no_falling_sun = new QCheckBox(page_resources);
    check_box_no_falling_sun->setText(tr("No Falling Sun"));
    check_box_auto_collect = new QCheckBox(page_resources);
    check_box_auto_collect->setText(tr("Auto Collect"));
    check_box_coin_disappear = new QCheckBox(page_resources);
    check_box_coin_disappear->setText(tr("Coin Disappear"));

    label_height = new QLabel(page_resources);
    label_height->setText(tr("Tree Height"));
    line_edit_height = new QLineEdit(page_resources);
    line_edit_height->setText("1000");
    line_edit_height->setValidator(new QIntValidator(0, 999999999, this));
    line_edit_height->setAlignment(Qt::AlignRight);
    push_button_height = new QPushButton(page_resources);
    push_button_height->setText(tr("Set"));
    push_button_all_shop_items = new QPushButton(page_resources);
    push_button_all_shop_items->setText(tr("Get All Shop Items"));

    check_box_fertilizer_unlimited = new QCheckBox(page_resources);
    check_box_fertilizer_unlimited->setText(tr("Fertilizer Unlimited"));
    check_box_bug_spray_unlimited = new QCheckBox(page_resources);
    check_box_bug_spray_unlimited->setText(tr("Bug Spray Unlimited"));
    check_box_chocolate_unlimited = new QCheckBox(page_resources);
    check_box_chocolate_unlimited->setText(tr("Chocolate Unlimited"));
    check_box_tree_food_unlimited = new QCheckBox(page_resources);
    check_box_tree_food_unlimited->setText(tr("Tree Food Unlimited"));

    layout_resources = new QGridLayout(page_resources);
    layout_resources->addWidget(label_sun, 0, 0, 1, 1);
    layout_resources->addWidget(line_edit_sun, 0, 1, 1, 1);
    layout_resources->addWidget(push_button_sun, 0, 2, 1, 1);
    layout_resources->addWidget(check_box_sun_limit, 0, 3, 1, 1);
    layout_resources->addWidget(label_money, 1, 0, 1, 1);
    layout_resources->addWidget(line_edit_money, 1, 1, 1, 1);
    layout_resources->addWidget(push_button_money, 1, 2, 1, 1);
    layout_resources->addWidget(check_box_money_limit, 1, 3, 1, 1);
    layout_resources->addWidget(check_box_many_falling_sun, 2, 0, 1, 1);
    layout_resources->addWidget(check_box_no_falling_sun, 2, 1, 1, 1);
    layout_resources->addWidget(check_box_auto_collect, 2, 2, 1, 1);
    layout_resources->addWidget(check_box_coin_disappear, 2, 3, 1, 1);
    layout_resources->addWidget(label_height, 3, 0, 1, 1);
    layout_resources->addWidget(line_edit_height, 3, 1, 1, 1);
    layout_resources->addWidget(push_button_height, 3, 2, 1, 1);
    layout_resources->addWidget(push_button_all_shop_items, 3, 3, 1, 1);
    layout_resources->addWidget(check_box_fertilizer_unlimited, 4, 0, 1, 1);
    layout_resources->addWidget(check_box_bug_spray_unlimited, 4, 1, 1, 1);
    layout_resources->addWidget(check_box_chocolate_unlimited, 4, 2, 1, 1);
    layout_resources->addWidget(check_box_tree_food_unlimited, 4, 3, 1, 1);

    for (int i = 0; i < layout_resources->rowCount(); i++)
        layout_resources->setRowStretch(i, 1);
    for (int i = 0; i < layout_resources->columnCount(); i++)
        layout_resources->setColumnStretch(i, 1);

    // Page 1 : Level

    page_level = new QWidget(this);

    push_button_gold_sunflower_trophy = new QPushButton(page_level);
    push_button_gold_sunflower_trophy->setText(tr("Get Gold Sunflower Trophy"));
    check_box_unlock_all_mode = new QCheckBox(page_level);
    check_box_unlock_all_mode->setText(tr("Unlock All Mode"));
    check_box_show_hide_games = new QCheckBox(page_level);
    check_box_show_hide_games->setText(tr("Show Hide Games"));
    push_button_win = new QPushButton(page_level);
    push_button_win->setText(tr("Direct Win"));

    label_endless = new QLabel(page_level);
    label_endless->setText(tr("Survival/Vasebreaker/I,Zombie Endless"));
    line_edit_level = new QLineEdit(page_level);
    line_edit_level->setText("1008");
    line_edit_level->setValidator(new QIntValidator(-1, 999999999, this));
    line_edit_level->setAlignment(Qt::AlignRight);
    push_button_jump_level = new QPushButton(page_level);
    push_button_jump_level->setText(tr("Jump Level"));

    combo_box_mixmode_menu = new QComboBox(page_level);
    combo_box_mixmode_menu->addItems(list_menu);
    combo_box_mixmode_menu->setCurrentIndex(0);

    combo_box_mixmode_adventure = new QComboBox(page_level);
    combo_box_mixmode_adventure->addItems(list_adventure);
    combo_box_mixmode_adventure->setCurrentIndex(0);
    combo_box_mixmode_minigames = new QComboBox(page_level);
    combo_box_mixmode_minigames->addItems(list_minigames);
    combo_box_mixmode_minigames->setCurrentIndex(0);
    combo_box_mixmode_puzzle = new QComboBox(page_level);
    combo_box_mixmode_puzzle->addItems(list_puzzle);
    combo_box_mixmode_puzzle->setCurrentIndex(0);
    combo_box_mixmode_survival = new QComboBox(page_level);
    combo_box_mixmode_survival->addItems(list_survival);
    combo_box_mixmode_survival->setCurrentIndex(0);

    stacked_widget_mixmode_choose = new QStackedWidget();
    stacked_widget_mixmode_choose->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    stacked_widget_mixmode_choose->addWidget(combo_box_mixmode_adventure);
    stacked_widget_mixmode_choose->addWidget(combo_box_mixmode_minigames);
    stacked_widget_mixmode_choose->addWidget(combo_box_mixmode_puzzle);
    stacked_widget_mixmode_choose->addWidget(combo_box_mixmode_survival);
    stacked_widget_mixmode_choose->setCurrentIndex(0);

    push_button_mixmode = new QPushButton(page_level);
    push_button_mixmode->setText(tr("Mix Mode"));

    label_scene_type = new QLabel(page_level);
    label_scene_type->setText(tr("Game Scene"));
    combo_box_scene_type = new QComboBox(page_level);
    combo_box_scene_type->addItems(list_game_scene);
    combo_box_scene_type->setCurrentIndex(0);
    push_button_scene_type = new QPushButton(page_level);
    push_button_scene_type->setText(tr("Set"));
    label_fc_caution = new QLabel(page_level);
    label_fc_caution->setText(tr("Likely Crash !"));
    label_fc_caution->setStyleSheet("QLabel { color: red; }");

    layout_level = new QGridLayout(page_level);
    layout_level->addWidget(push_button_gold_sunflower_trophy, 0, 0, 1, 1);
    layout_level->addWidget(check_box_unlock_all_mode, 0, 1, 1, 1);
    layout_level->addWidget(check_box_show_hide_games, 0, 2, 1, 1);
    layout_level->addWidget(push_button_win, 0, 3, 1, 1);
    layout_level->addWidget(label_endless, 1, 0, 1, 2);
    layout_level->addWidget(line_edit_level, 1, 2, 1, 1);
    layout_level->addWidget(push_button_jump_level, 1, 3, 1, 1);
    layout_level->addWidget(combo_box_mixmode_menu, 2, 0, 1, 1);
    layout_level->addWidget(stacked_widget_mixmode_choose, 2, 1, 1, 2);
    layout_level->addWidget(push_button_mixmode, 2, 3, 1, 1);
    layout_level->addWidget(label_scene_type, 3, 0, 1, 1);
    layout_level->addWidget(combo_box_scene_type, 3, 1, 1, 1);
    layout_level->addWidget(push_button_scene_type, 3, 2, 1, 1);
    layout_level->addWidget(label_fc_caution, 3, 3, 1, 1);

    for (int i = 0; i < layout_level->rowCount(); i++)
        layout_level->setRowStretch(i, 1);
    for (int i = 0; i < layout_level->columnCount(); i++)
        layout_level->setColumnStretch(i, 1);

    // Page 2 : Plants

    page_plant = new QWidget(this);

    check_box_cob_cannon_nocd = new QCheckBox(page_plant);
    check_box_cob_cannon_nocd->setText(tr("Cob Cannon NoCD"));
    check_box_magnets_nocd = new QCheckBox(page_plant);
    check_box_magnets_nocd->setText(tr("Magnets NoCD"));
    check_box_potato_mine_nocd = new QCheckBox(page_plant);
    check_box_potato_mine_nocd->setText(tr("Potato Mine NoCD"));
    check_box_chomper_nocd = new QCheckBox(page_plant);
    check_box_chomper_nocd->setText(tr("Chomper NoCD"));

    check_box_plant_invincible = new QCheckBox(page_plant);
    check_box_plant_invincible->setText(tr("Plant Invincible"));
    check_box_plant_weak = new QCheckBox(page_plant);
    check_box_plant_weak->setText(tr("Plant Weak"));
    check_box_lock_kernel = new QCheckBox(page_plant);
    check_box_lock_kernel->setText(tr("Lock Kernel"));
    check_box_lock_butter = new QCheckBox(page_plant);
    check_box_lock_butter->setText(tr("Lock Butter"));

    check_box_no_crater = new QCheckBox(page_plant);
    check_box_no_crater->setText(tr("No Crater"));
    check_box_mushrooms_awake = new QCheckBox(page_plant);
    check_box_mushrooms_awake->setText(tr("Mushrooms Awake"));
    check_box_strong_blover = new QCheckBox(page_plant);
    check_box_strong_blover->setText(tr("Strong Blover"));
    check_box_strong_peas = new QCheckBox(page_plant);
    check_box_strong_peas->setText(tr("Strong Peas"));

    check_box_umbrella = new QCheckBox(page_plant);
    check_box_umbrella->setText(tr("Plant Umbrella"));
    check_box_beghouled_free_move = new QCheckBox(page_plant);
    check_box_beghouled_free_move->setText(tr("Beghouled Free Move"));
    check_box_produce_speed_up = new QCheckBox(page_plant);
    check_box_produce_speed_up->setText(tr("Produce Speed Up"));
    check_box_attack_speed_up = new QCheckBox(page_plant);
    check_box_attack_speed_up->setText(tr("Attack Speed Up"));

    label_plant_damage = new QLabel(page_plant);
    label_plant_damage->setText(tr("Damage"));
    combo_box_plant_projectile = new QComboBox(page_plant);
    combo_box_plant_projectile->addItems(list_projectile);
    combo_box_plant_projectile->setCurrentIndex(0);
    line_edit_plant_damage = new QLineEdit(page_plant);
    line_edit_plant_damage->setText("");
    line_edit_plant_damage->setValidator(new QIntValidator(0, 999999999, this));
    line_edit_plant_damage->setAlignment(Qt::AlignRight);
    push_button_plant_damage = new QPushButton(page_plant);
    push_button_plant_damage->setText(tr("Set"));

    layout_plant = new QGridLayout(page_plant);
    layout_plant->addWidget(check_box_cob_cannon_nocd, 0, 0, 1, 1);
    layout_plant->addWidget(check_box_magnets_nocd, 0, 1, 1, 1);
    layout_plant->addWidget(check_box_potato_mine_nocd, 0, 2, 1, 1);
    layout_plant->addWidget(check_box_chomper_nocd, 0, 3, 1, 1);
    layout_plant->addWidget(check_box_plant_invincible, 1, 0, 1, 1);
    layout_plant->addWidget(check_box_plant_weak, 1, 1, 1, 1);
    layout_plant->addWidget(check_box_lock_kernel, 1, 2, 1, 1);
    layout_plant->addWidget(check_box_lock_butter, 1, 3, 1, 1);
    layout_plant->addWidget(check_box_no_crater, 2, 0, 1, 1);
    layout_plant->addWidget(check_box_mushrooms_awake, 2, 1, 1, 1);
    layout_plant->addWidget(check_box_strong_blover, 2, 2, 1, 1);
    layout_plant->addWidget(check_box_strong_peas, 2, 3, 1, 1);
    layout_plant->addWidget(check_box_umbrella, 3, 0, 1, 1);
    layout_plant->addWidget(check_box_beghouled_free_move, 3, 1, 1, 1);
    layout_plant->addWidget(check_box_produce_speed_up, 3, 2, 1, 1);
    layout_plant->addWidget(check_box_attack_speed_up, 3, 3, 1, 1);
    layout_plant->addWidget(label_plant_damage, 4, 0, 1, 1);
    layout_plant->addWidget(combo_box_plant_projectile, 4, 1, 1, 1);
    layout_plant->addWidget(line_edit_plant_damage, 4, 2, 1, 1);
    layout_plant->addWidget(push_button_plant_damage, 4, 3, 1, 1);

    for (int i = 0; i < layout_plant->rowCount(); i++)
        layout_plant->setRowStretch(i, 1);
    for (int i = 0; i < layout_plant->columnCount(); i++)
        layout_plant->setColumnStretch(i, 1);

    // Page 3 : Zombies

    page_zombie = new QWidget(this);

    check_box_zombie_explode_immediately = new QCheckBox(page_zombie);
    check_box_zombie_explode_immediately->setText(tr("Immediately Explode"));
    check_box_zombie_explode_never = new QCheckBox(page_zombie);
    check_box_zombie_explode_never->setText(tr("Never Explode"));

    check_box_zombie_invisible = new QCheckBox(page_zombie);
    check_box_zombie_invisible->setText(tr("Zombie Invisible"));
    check_box_zombie_show = new QCheckBox(page_zombie);
    check_box_zombie_show->setText(tr("Zombie Show"));

    check_box_zombie_weak = new QCheckBox(page_zombie);
    check_box_zombie_weak->setText(tr("Zombie Weak"));
    check_box_zombie_invincible = new QCheckBox(page_zombie);
    check_box_zombie_invincible->setText(tr("Zombie Invincible"));

    check_box_stop_spawning = new QCheckBox(page_zombie);
    check_box_stop_spawning->setText(tr("Stop Spawning"));
    check_box_zombies_no_move = new QCheckBox(page_zombie);
    check_box_zombies_no_move->setText(tr("Zombies No Move"));

    check_box_no_ice_slow_down = new QCheckBox(page_zombie);
    check_box_no_ice_slow_down->setText(tr("No Ice Slow Down"));
    check_box_no_butter_immobilize = new QCheckBox(page_zombie);
    check_box_no_butter_immobilize->setText(tr("No Butter Immobilize"));
    check_box_no_3_zombies_group = new QCheckBox(page_zombie);
    check_box_no_3_zombies_group->setText(tr("No 3 Zombies Group"));
    check_box_no_ice_trail = new QCheckBox(page_zombie);
    check_box_no_ice_trail->setText(tr("No Ice Trail"));

    check_box_no_throw_imp = new QCheckBox(page_zombie);
    check_box_no_throw_imp->setText(tr("No Throw Imp"));
    check_box_gargantuar_eatable = new QCheckBox(page_zombie);
    check_box_gargantuar_eatable->setText(tr("Gargantuar Eatable"));
    check_box_zomboss_no_move = new QCheckBox(page_zombie);
    check_box_zomboss_no_move->setText(tr("Zomboss No Move"));
    check_box_balloon_burst = new QCheckBox(page_zombie);
    check_box_balloon_burst->setText(tr("Balloon Burst"));

    check_box_gather_zombies = new QCheckBox(page_zombie);
    check_box_gather_zombies->setText(tr("Gather Zombies"));
    slider_gather_zombies = new QSlider(page_zombie);
    slider_gather_zombies->setOrientation(Qt::Horizontal);
    slider_gather_zombies->setMinimum(0);
    slider_gather_zombies->setMaximum(800);
    slider_gather_zombies->setSingleStep(1);
    slider_gather_zombies->setPageStep(100);
    slider_gather_zombies->setValue(600);

    push_button_spawning_all_zombies = new QPushButton(page_zombie);
    push_button_spawning_all_zombies->setText(tr("Spawning All"));
    label_all_zombies = new QLabel(page_zombie);
    label_all_zombies->setText(tr("All Zombies"));
    label_all_zombies->setAlignment(Qt::AlignCenter);
    combo_box_all_zombies = new QComboBox(page_zombie);
    combo_box_all_zombies->addItems(list_zombie_status);
    combo_box_all_zombies->setCurrentIndex(0);
    push_button_all_zombies = new QPushButton(page_zombie);
    push_button_all_zombies->setText(tr("Set"));

    layout_zombie = new QGridLayout(page_zombie);
    layout_zombie->addWidget(check_box_zombie_explode_immediately, 0, 0, 1, 1);
    layout_zombie->addWidget(check_box_zombie_explode_never, 0, 1, 1, 1);
    layout_zombie->addWidget(check_box_zombie_invisible, 1, 0, 1, 1);
    layout_zombie->addWidget(check_box_zombie_show, 1, 1, 1, 1);
    layout_zombie->addWidget(check_box_zombie_weak, 2, 0, 1, 1);
    layout_zombie->addWidget(check_box_zombie_invincible, 2, 1, 1, 1);
    layout_zombie->addWidget(check_box_stop_spawning, 3, 0, 1, 1);
    layout_zombie->addWidget(check_box_zombies_no_move, 3, 1, 1, 1);
    layout_zombie->addWidget(check_box_no_ice_slow_down, 0, 2, 1, 1);
    layout_zombie->addWidget(check_box_no_butter_immobilize, 0, 3, 1, 1);
    layout_zombie->addWidget(check_box_no_3_zombies_group, 1, 2, 1, 1);
    layout_zombie->addWidget(check_box_no_ice_trail, 1, 3, 1, 1);
    layout_zombie->addWidget(check_box_no_throw_imp, 2, 2, 1, 1);
    layout_zombie->addWidget(check_box_gargantuar_eatable, 2, 3, 1, 1);
    layout_zombie->addWidget(check_box_zomboss_no_move, 3, 2, 1, 1);
    layout_zombie->addWidget(check_box_balloon_burst, 3, 3, 1, 1);
    layout_zombie->addWidget(check_box_gather_zombies, 4, 0, 1, 1);
    layout_zombie->addWidget(slider_gather_zombies, 4, 1, 1, 3);
    layout_zombie->addWidget(push_button_spawning_all_zombies, 5, 0, 1, 1);
    layout_zombie->addWidget(label_all_zombies, 5, 1, 1, 1);
    layout_zombie->addWidget(combo_box_all_zombies, 5, 2, 1, 1);
    layout_zombie->addWidget(push_button_all_zombies, 5, 3, 1, 1);

    for (int i = 0; i < layout_zombie->rowCount(); i++)
        layout_zombie->setRowStretch(i, 1);
    for (int i = 0; i < layout_zombie->columnCount(); i++)
        layout_zombie->setColumnStretch(i, 1);

    // Page 4 : Spawn

    page_spawn = new QWidget(this);

    widget_spawn_brief = new QWidget(page_spawn);

    check_box_spawn_2 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_3 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_4 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_5 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_6 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_7 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_8 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_11 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_12 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_14 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_15 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_16 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_17 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_18 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_19 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_20 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_21 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_22 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_23 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_32 = new QCheckBox(widget_spawn_brief);
    check_box_spawn_2->setText(list_zombie[2]);
    check_box_spawn_3->setText(list_zombie[3]);
    check_box_spawn_4->setText(list_zombie[4]);
    check_box_spawn_5->setText(list_zombie[5]);
    check_box_spawn_6->setText(list_zombie[6]);
    check_box_spawn_7->setText(list_zombie[7]);
    check_box_spawn_8->setText(list_zombie[8]);
    check_box_spawn_11->setText(list_zombie[11]);
    check_box_spawn_12->setText(list_zombie[12]);
    check_box_spawn_14->setText(list_zombie[14]);
    check_box_spawn_15->setText(list_zombie[15]);
    check_box_spawn_16->setText(list_zombie[16]);
    check_box_spawn_17->setText(list_zombie[17]);
    check_box_spawn_18->setText(list_zombie[18]);
    check_box_spawn_19->setText(list_zombie[19]);
    check_box_spawn_20->setText(list_zombie[20]);
    check_box_spawn_21->setText(list_zombie[21]);
    check_box_spawn_22->setText(list_zombie[22]);
    check_box_spawn_23->setText(list_zombie[23]);
    check_box_spawn_32->setText(list_zombie[32]);

    layout_spawn_brief = new QGridLayout(widget_spawn_brief);
    layout_spawn_brief->addWidget(check_box_spawn_2, 0, 0, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_3, 0, 1, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_4, 0, 2, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_5, 0, 3, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_6, 0, 4, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_7, 1, 0, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_8, 1, 1, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_11, 1, 2, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_12, 1, 3, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_14, 1, 4, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_15, 2, 0, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_16, 2, 1, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_17, 2, 2, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_18, 2, 3, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_19, 2, 4, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_20, 3, 0, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_21, 3, 1, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_22, 3, 2, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_23, 3, 3, 1, 1);
    layout_spawn_brief->addWidget(check_box_spawn_32, 3, 4, 1, 1);
    layout_spawn_brief->setRowStretch(0, 1);
    layout_spawn_brief->setRowStretch(1, 1);
    layout_spawn_brief->setRowStretch(2, 1);
    layout_spawn_brief->setRowStretch(3, 1);
    layout_spawn_brief->setColumnStretch(0, 1);
    layout_spawn_brief->setColumnStretch(1, 1);
    layout_spawn_brief->setColumnStretch(2, 1);
    layout_spawn_brief->setColumnStretch(3, 1);
    layout_spawn_brief->setColumnStretch(4, 1);

    push_button_natural_spawn = new QPushButton(page_spawn);
    push_button_natural_spawn->setText(tr("Natural Spawn"));
    push_button_extreme_spawn = new QPushButton(page_spawn);
    push_button_extreme_spawn->setText(tr("Extreme Spawn"));

    check_box_detailed_mode = new QCheckBox(page_spawn);
    check_box_detailed_mode->setText(tr("Detailed Mode"));

    line_edit_random_seed = new QLineEdit(page_spawn);
    line_edit_random_seed->setText("00000000");
    QRegExp reg_exp_hex("[a-fA-F0-9]{8}");
    line_edit_random_seed->setValidator(new QRegExpValidator(reg_exp_hex, this));
    line_edit_random_seed->setAlignment(Qt::AlignLeft);
    push_button_random_seed = new QPushButton(page_spawn);
    push_button_random_seed->setText(tr("Set Seed"));

    combo_box_spawn_menu = new QComboBox(page_spawn);
    combo_box_spawn_menu->addItems(list_zombie);
    combo_box_spawn_menu->setCurrentIndex(0);
    push_button_spawn_add = new QPushButton(page_spawn);
    push_button_spawn_add->setText(tr("Add >>"));
    push_button_spawn_delete = new QPushButton(page_spawn);
    push_button_spawn_delete->setText(tr("<< Delete"));
    push_button_spawn_clear = new QPushButton(page_spawn);
    push_button_spawn_clear->setText(tr("Clear List"));

    radio_button_natural_spawn = new QRadioButton(page_spawn);
    radio_button_natural_spawn->setText(tr("Natural Spawn"));
    radio_button_extreme_spawn = new QRadioButton(page_spawn);
    radio_button_extreme_spawn->setText(tr("Extreme Spawn"));

    check_box_evenly_filled = new QCheckBox(page_spawn);
    check_box_evenly_filled->setText(tr("Evenly Filled"));
    check_box_limit_yeti = new QCheckBox(page_spawn);
    check_box_limit_yeti->setText(tr("Limit Yeti"));
    check_box_limit_bungee = new QCheckBox(page_spawn);
    check_box_limit_bungee->setText(tr("Limit Bungee"));
    check_box_limit_giga = new QCheckBox(page_spawn);
    check_box_limit_giga->setText(tr("Limit Giga"));

    push_button_spawn_original = new QPushButton(page_spawn);
    push_button_spawn_original->setText(tr("Reset"));
    push_button_spawn_set = new QPushButton(page_spawn);
    push_button_spawn_set->setText(tr("Set"));

    list_widget_spawn = new QListWidget(page_spawn);

    spacer_spawn_0 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
    spacer_spawn_1 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
    spacer_spawn_2 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
    spacer_spawn_3 = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);

    // Set default status, Checked and Visible.
    radio_button_natural_spawn->setChecked(true);
    check_box_evenly_filled->setChecked(true);
    check_box_limit_yeti->setChecked(true);
    check_box_limit_bungee->setChecked(true);
    check_box_evenly_filled->setEnabled(false);
    check_box_limit_yeti->setEnabled(false);
    check_box_limit_bungee->setEnabled(false);
    check_box_limit_giga->setEnabled(false);
    line_edit_random_seed->setVisible(false);
    push_button_random_seed->setVisible(false);
    combo_box_spawn_menu->setVisible(false);
    push_button_spawn_add->setVisible(false);
    push_button_spawn_delete->setVisible(false);
    push_button_spawn_clear->setVisible(false);
    radio_button_natural_spawn->setVisible(false);
    radio_button_extreme_spawn->setVisible(false);
    check_box_evenly_filled->setVisible(false);
    check_box_limit_yeti->setVisible(false);
    check_box_limit_bungee->setVisible(false);
    check_box_limit_giga->setVisible(false);
    push_button_spawn_original->setVisible(false);
    push_button_spawn_set->setVisible(false);
    list_widget_spawn->setVisible(false);

    layout_spawn = new QGridLayout(page_spawn);
    layout_spawn->addWidget(widget_spawn_brief, 0, 0, 8, 4);
    layout_spawn->addWidget(push_button_natural_spawn, 8, 2, 1, 1);
    layout_spawn->addWidget(push_button_extreme_spawn, 8, 3, 1, 1);
    layout_spawn->addWidget(check_box_detailed_mode, 8, 0, 1, 1);
    layout_spawn->addWidget(line_edit_random_seed, 0, 0, 1, 1);
    layout_spawn->addWidget(push_button_random_seed, 2, 0, 1, 1);
    layout_spawn->addWidget(combo_box_spawn_menu, 0, 1, 1, 1);
    layout_spawn->addWidget(push_button_spawn_add, 0, 2, 1, 1);
    layout_spawn->addWidget(push_button_spawn_delete, 2, 2, 1, 1);
    layout_spawn->addWidget(push_button_spawn_clear, 2, 1, 1, 1);
    layout_spawn->addWidget(radio_button_natural_spawn, 4, 1, 1, 1);
    layout_spawn->addWidget(radio_button_extreme_spawn, 4, 2, 1, 1);
    layout_spawn->addWidget(check_box_evenly_filled, 4, 0, 1, 1);
    layout_spawn->addWidget(check_box_limit_yeti, 6, 0, 1, 1);
    layout_spawn->addWidget(check_box_limit_bungee, 6, 1, 1, 1);
    layout_spawn->addWidget(check_box_limit_giga, 6, 2, 1, 1);
    layout_spawn->addWidget(push_button_spawn_original, 8, 1, 1, 1);
    layout_spawn->addWidget(push_button_spawn_set, 8, 2, 1, 1);
    layout_spawn->addWidget(list_widget_spawn, 0, 3, 9, 1);
    layout_spawn->addItem(spacer_spawn_0, 1, 0, 1, 1);
    layout_spawn->addItem(spacer_spawn_1, 3, 0, 1, 1);
    layout_spawn->addItem(spacer_spawn_2, 5, 0, 1, 1);
    layout_spawn->addItem(spacer_spawn_3, 7, 0, 1, 1);

    for (int i = 0; i < layout_spawn->rowCount(); i++)
        layout_spawn->setRowStretch(i, 1);
    for (int i = 0; i < layout_spawn->columnCount(); i++)
        layout_spawn->setColumnStretch(i, 1);
    // layout_spawn->setMargin(30); // TODO
    // layout_spawn->setContentsMargins(0, 0, 0, 0);
    // layout_spawn->setSpacing(10);

    // Page 5 : Slots

    page_slots = new QWidget(this);

    label_slots_count = new QLabel(page_slots);
    label_slots_count->setText(tr("Count of Slots"));
    spin_box_slots_count = new QSpinBox(page_slots);
    spin_box_slots_count->setRange(1, 10);
    spin_box_slots_count->setSingleStep(1);
    spin_box_slots_count->setValue(10);
    push_button_slots_count = new QPushButton(page_slots);
    push_button_slots_count->setText(tr("Set"));
    push_button_show_shovel = new QPushButton(page_slots);
    push_button_show_shovel->setText(tr("Show Shovel"));

    combo_box_slots_slot = new QComboBox(page_slots);
    combo_box_slots_slot->addItems(list_slots_index);
    combo_box_slots_slot->setCurrentIndex(0);
    combo_box_slots_seed = new QComboBox(page_slots);
    combo_box_slots_seed->addItems(list_slots_seed);
    combo_box_slots_seed->setCurrentIndex(0);
    push_button_slots_set = new QPushButton(page_slots);
    push_button_slots_set->setText(tr("Set"));
    check_box_slots_imitater = new QCheckBox(page_slots);
    check_box_slots_imitater->setText(tr("Imitater"));

    check_box_slots_purple_seed_unlimited = new QCheckBox(page_slots);
    check_box_slots_purple_seed_unlimited->setText(tr("Purple Seed Unlimited"));
    check_box_planting_freely = new QCheckBox(page_slots);
    check_box_planting_freely->setText(tr("Planting Freely"));
    check_box_slots_belt_no_delay = new QCheckBox(page_slots);
    check_box_slots_belt_no_delay->setText(tr("Belt No Delay"));
    check_box_lock_shovel = new QCheckBox(page_slots);
    check_box_lock_shovel->setText(tr("Lock Shovel"));

    combo_box_seed = new QComboBox(page_slots);
    for (int i = 0; i < 48; i++)
        combo_box_seed->addItem(list_slots_seed[i]);
    combo_box_seed->setCurrentIndex(0);

    check_box_ignore_sun = new QCheckBox(page_slots);
    check_box_ignore_sun->setText(tr("Ignore Sun"));
    check_box_slots_no_cool_down = new QCheckBox(page_slots);
    check_box_slots_no_cool_down->setText(tr("Seed No Cool Down"));

    label_seed_speed = new QLabel(page_slots);
    label_seed_speed->setText(tr("Speed"));
    label_seed_speed->setAlignment(Qt::AlignCenter);
    line_edit_seed_speed = new QLineEdit(page_slots);
    line_edit_seed_speed->setText("");
    line_edit_seed_speed->setValidator(new QIntValidator(0, 999999999, this));
    push_button_seed_speed = new QPushButton(page_slots);
    push_button_seed_speed->setText(tr("Set"));

    label_seed_cost = new QLabel(page_slots);
    label_seed_cost->setText(tr("Cost"));
    label_seed_cost->setAlignment(Qt::AlignCenter);
    line_edit_seed_cost = new QLineEdit(page_slots);
    line_edit_seed_cost->setText("");
    line_edit_seed_cost->setValidator(new QIntValidator(0, 999999999, this));
    push_button_seed_cost = new QPushButton(page_slots);
    push_button_seed_cost->setText(tr("Set"));

    label_seed_recharge = new QLabel(page_slots);
    label_seed_recharge->setText(tr("Recharge"));
    label_seed_recharge->setAlignment(Qt::AlignCenter);
    line_edit_seed_recharge = new QLineEdit(page_slots);
    line_edit_seed_recharge->setText("");
    line_edit_seed_recharge->setValidator(new QIntValidator(0, 999999999, this));
    push_button_seed_recharge = new QPushButton(page_slots);
    push_button_seed_recharge->setText(tr("Set"));

    layout_slots = new QGridLayout(page_slots);
    layout_slots->addWidget(label_slots_count, 0, 0, 1, 1);
    layout_slots->addWidget(spin_box_slots_count, 0, 1, 1, 1);
    layout_slots->addWidget(push_button_slots_count, 0, 2, 1, 1);
    layout_slots->addWidget(push_button_show_shovel, 0, 3, 1, 1);
    layout_slots->addWidget(combo_box_slots_slot, 1, 0, 1, 1);
    layout_slots->addWidget(combo_box_slots_seed, 1, 1, 1, 1);
    layout_slots->addWidget(push_button_slots_set, 1, 2, 1, 1);
    layout_slots->addWidget(check_box_slots_imitater, 1, 3, 1, 1);
    layout_slots->addWidget(check_box_slots_purple_seed_unlimited, 2, 0, 1, 1);
    layout_slots->addWidget(check_box_planting_freely, 2, 1, 1, 1);
    layout_slots->addWidget(check_box_slots_belt_no_delay, 2, 2, 1, 1);
    layout_slots->addWidget(check_box_lock_shovel, 2, 3, 1, 1);
    layout_slots->addWidget(combo_box_seed, 3, 0, 1, 1);
    layout_slots->addWidget(check_box_ignore_sun, 4, 0, 1, 1);
    layout_slots->addWidget(check_box_slots_no_cool_down, 5, 0, 1, 1);
    layout_slots->addWidget(label_seed_speed, 3, 1, 1, 1);
    layout_slots->addWidget(line_edit_seed_speed, 3, 2, 1, 1);
    layout_slots->addWidget(push_button_seed_speed, 3, 3, 1, 1);
    layout_slots->addWidget(label_seed_cost, 4, 1, 1, 1);
    layout_slots->addWidget(line_edit_seed_cost, 4, 2, 1, 1);
    layout_slots->addWidget(push_button_seed_cost, 4, 3, 1, 1);
    layout_slots->addWidget(label_seed_recharge, 5, 1, 1, 1);
    layout_slots->addWidget(line_edit_seed_recharge, 5, 2, 1, 1);
    layout_slots->addWidget(push_button_seed_recharge, 5, 3, 1, 1);

    for (int i = 0; i < layout_slots->rowCount(); i++)
        layout_slots->setRowStretch(i, 1);
    for (int i = 0; i < layout_slots->columnCount(); i++)
        layout_slots->setColumnStretch(i, 1);

    // Page 6 : Scene

    page_scene = new QWidget(this);

    label_scene_row = new QLabel(page_scene);
    label_scene_row->setText(tr("Row"));
    label_scene_col = new QLabel(page_scene);
    label_scene_col->setText(tr("Col"));

    spin_box_scene_row = new QSpinBox(page_scene);
    spin_box_scene_row->setRange(0, 99);
    spin_box_scene_row->setSingleStep(1);
    spin_box_scene_row->setValue(0);
    spin_box_scene_col = new QSpinBox(page_scene);
    spin_box_scene_col->setRange(0, 999);
    spin_box_scene_col->setSingleStep(1);
    spin_box_scene_col->setValue(0);

    combo_box_plant_menu = new QComboBox(page_scene);
    for (int i = 0; i < 51; i++)
        combo_box_plant_menu->addItem(list_slots_seed[i]);
    combo_box_plant_menu->setCurrentIndex(0);
    push_button_put_plant = new QPushButton(page_scene);
    push_button_put_plant->setText(tr("Planting"));
    check_box_plant_imitater = new QCheckBox(page_scene);
    check_box_plant_imitater->setText(tr("Imitater"));

    combo_box_zombie_menu = new QComboBox(page_scene);
    combo_box_zombie_menu->addItems(list_zombie);
    combo_box_zombie_menu->setCurrentIndex(0);
    push_button_put_zombie = new QPushButton(page_scene);
    push_button_put_zombie->setText(tr("Put"));

    push_button_put_grave = new QPushButton(page_scene);
    push_button_put_grave->setText(tr("Grave"));
    push_button_put_ladder = new QPushButton(page_scene);
    push_button_put_ladder->setText(tr("Ladder"));
    push_button_auto_ladder = new QPushButton(page_scene);
    push_button_auto_ladder->setText(tr("Ladder Pumpkin"));
    check_box_imitater_pumpkin_only = new QCheckBox(page_scene);
    check_box_imitater_pumpkin_only->setText(tr("Imitater Pumpkin Only"));
    check_box_imitater_pumpkin_only->setChecked(true); // Set default status.

    push_button_eat_all_graves = new QPushButton(page_scene);
    push_button_eat_all_graves->setText(tr("Eat All Graves"));
    push_button_lily_pad_on_pool = new QPushButton(page_scene);
    push_button_lily_pad_on_pool->setText(tr("Lily Pad On Pool"));
    push_button_flower_pot_on_roof = new QPushButton(page_scene);
    push_button_flower_pot_on_roof->setText(tr("Flower Pot On Roof"));
    push_button_clear_all_plants = new QPushButton(page_scene);
    push_button_clear_all_plants->setText(tr("Clear All Plants"));

    label_block_type = new QLabel(page_scene);
    label_block_type->setText(tr("Block Type"));
    combo_box_block_type = new QComboBox(page_scene);
    combo_box_block_type->addItem(tr("Lawn"));
    combo_box_block_type->addItem(tr("Bare"));
    combo_box_block_type->addItem(tr("Pool"));
    combo_box_block_type->setCurrentIndex(0);
    push_button_block_type = new QPushButton(page_scene);
    push_button_block_type->setText(tr("Set"));

    combo_box_scene_row = new QComboBox(page_scene);
    combo_box_scene_row->addItems(list_rows);
    combo_box_scene_row->setCurrentIndex(0);
    combo_box_row_type = new QComboBox(page_scene);
    combo_box_row_type->addItem(tr("None"));
    combo_box_row_type->addItem(tr("Land"));
    combo_box_row_type->addItem(tr("Water"));
    combo_box_row_type->setCurrentIndex(0);
    push_button_row_type = new QPushButton(page_scene);
    push_button_row_type->setText(tr("Set"));

    push_button_start_lawn_mowers = new QPushButton(page_scene);
    push_button_start_lawn_mowers->setText(tr("Start Lawn Mowers"));
    push_button_reset_lawn_mowers = new QPushButton(page_scene);
    push_button_reset_lawn_mowers->setText(tr("Reset Lawn Mowers"));

    layout_scene = new QGridLayout(page_scene);
    layout_scene->addWidget(label_scene_row, 0, 0, 1, 1);
    layout_scene->addWidget(label_scene_col, 1, 0, 1, 1);
    layout_scene->addWidget(spin_box_scene_row, 0, 1, 1, 1);
    layout_scene->addWidget(spin_box_scene_col, 1, 1, 1, 1);
    layout_scene->addWidget(combo_box_plant_menu, 0, 2, 1, 2);
    layout_scene->addWidget(push_button_put_plant, 0, 4, 1, 2);
    layout_scene->addWidget(check_box_plant_imitater, 0, 6, 1, 2);
    layout_scene->addWidget(combo_box_zombie_menu, 1, 2, 1, 2);
    layout_scene->addWidget(push_button_put_zombie, 1, 4, 1, 2);
    layout_scene->addWidget(push_button_put_grave, 2, 0, 1, 2);
    layout_scene->addWidget(push_button_put_ladder, 2, 2, 1, 2);
    layout_scene->addWidget(push_button_auto_ladder, 2, 4, 1, 2);
    layout_scene->addWidget(check_box_imitater_pumpkin_only, 2, 6, 1, 2);
    layout_scene->addWidget(push_button_eat_all_graves, 3, 0, 1, 2);
    layout_scene->addWidget(push_button_lily_pad_on_pool, 3, 2, 1, 2);
    layout_scene->addWidget(push_button_flower_pot_on_roof, 3, 4, 1, 2);
    layout_scene->addWidget(push_button_clear_all_plants, 3, 6, 1, 2);
    layout_scene->addWidget(label_block_type, 4, 0, 1, 2);
    layout_scene->addWidget(combo_box_block_type, 4, 2, 1, 2);
    layout_scene->addWidget(push_button_block_type, 4, 4, 1, 2);
    layout_scene->addWidget(combo_box_scene_row, 5, 0, 1, 2);
    layout_scene->addWidget(combo_box_row_type, 5, 2, 1, 2);
    layout_scene->addWidget(push_button_row_type, 5, 4, 1, 2);
    layout_scene->addWidget(push_button_start_lawn_mowers, 4, 6, 1, 2);
    layout_scene->addWidget(push_button_reset_lawn_mowers, 5, 6, 1, 2);

    for (int i = 0; i < layout_scene->rowCount(); i++)
        layout_scene->setRowStretch(i, 1);
    for (int i = 0; i < layout_scene->columnCount(); i++)
        layout_scene->setColumnStretch(i, 1);

    // Page 7 : Effects

    page_effects = new QWidget(this);

    push_button_code_sukhbir = new QPushButton(page_effects);
    push_button_code_sukhbir->setText(tr("SUKHBIR"));
    push_button_code_future = new QPushButton(page_effects);
    push_button_code_future->setText(tr("FUTURE"));
    push_button_code_mustache = new QPushButton(page_effects);
    push_button_code_mustache->setText(tr("MUSTACHE"));
    push_button_code_trickedout = new QPushButton(page_effects);
    push_button_code_trickedout->setText(tr("TRICKEDOUT"));
    push_button_code_daisies = new QPushButton(page_effects);
    push_button_code_daisies->setText(tr("DAISIES"));
    push_button_code_dance = new QPushButton(page_effects);
    push_button_code_dance->setText(tr("DANCE"));
    push_button_code_pinata = new QPushButton(page_effects);
    push_button_code_pinata->setText(tr("PINATA"));
    push_button_code_konami = new QPushButton(page_effects);
    push_button_code_konami->setText(tr("KONAMI"));

    check_box_effect_little_zombie = new QCheckBox(page_effects);
    check_box_effect_little_zombie->setText(tr("Little Zombie"));
    check_box_effect_its_raining = new QCheckBox(page_effects);
    check_box_effect_its_raining->setText(tr("It's Raining"));
    check_box_effect_stormy_night = new QCheckBox(page_effects);
    check_box_effect_stormy_night->setText(tr("Stormy Night"));
    check_box_effect_high_gravity = new QCheckBox(page_effects);
    check_box_effect_high_gravity->setText(tr("High Gravity"));
    check_box_effect_column_like = new QCheckBox(page_effects);
    check_box_effect_column_like->setText(tr("Column Like"));
    check_box_effect_zombie_quick = new QCheckBox(page_effects);
    check_box_effect_zombie_quick->setText(tr("Zombie Quick"));

    label_ice_trail_x = new QLabel(page_effects);
    label_ice_trail_x->setText(tr("Ice Trail X Coordinate"));
    combo_box_ice_trail_x = new QComboBox(page_effects);
    combo_box_ice_trail_x->addItems(list_rows);
    combo_box_ice_trail_x->setCurrentIndex(0);
    line_edit_ice_trail_x = new QLineEdit(page_effects);
    line_edit_ice_trail_x->setText("");
    line_edit_ice_trail_x->setValidator(new QIntValidator(-9999, 9999, this));
    line_edit_ice_trail_x->setAlignment(Qt::AlignRight);
    push_button_ice_trail_x = new QPushButton(page_effects);
    push_button_ice_trail_x->setText(tr("Set"));

    check_box_full_fog = new QCheckBox(page_effects);
    check_box_full_fog->setText(tr("Full Fog"));
    check_box_no_fog = new QCheckBox(page_effects);
    check_box_no_fog->setText(tr("No Fog"));
    check_box_see_vase = new QCheckBox(page_effects);
    check_box_see_vase->setText(tr("See Vase"));

    layout_effects = new QGridLayout(page_effects);
    layout_effects->addWidget(push_button_code_sukhbir, 0, 0, 1, 3);
    layout_effects->addWidget(push_button_code_future, 0, 3, 1, 3);
    layout_effects->addWidget(push_button_code_mustache, 0, 6, 1, 3);
    layout_effects->addWidget(push_button_code_trickedout, 0, 9, 1, 3);
    layout_effects->addWidget(push_button_code_daisies, 1, 0, 1, 3);
    layout_effects->addWidget(push_button_code_dance, 1, 3, 1, 3);
    layout_effects->addWidget(push_button_code_pinata, 1, 6, 1, 3);
    layout_effects->addWidget(push_button_code_konami, 1, 9, 1, 3);
    layout_effects->addWidget(check_box_effect_little_zombie, 2, 0, 1, 4);
    layout_effects->addWidget(check_box_effect_its_raining, 2, 4, 1, 4);
    layout_effects->addWidget(check_box_effect_stormy_night, 2, 8, 1, 4);
    layout_effects->addWidget(check_box_effect_high_gravity, 3, 0, 1, 4);
    layout_effects->addWidget(check_box_effect_column_like, 3, 4, 1, 4);
    layout_effects->addWidget(check_box_effect_zombie_quick, 3, 8, 1, 4);
    layout_effects->addWidget(label_ice_trail_x, 4, 0, 1, 3);
    layout_effects->addWidget(combo_box_ice_trail_x, 4, 3, 1, 3);
    layout_effects->addWidget(line_edit_ice_trail_x, 4, 6, 1, 3);
    layout_effects->addWidget(push_button_ice_trail_x, 4, 9, 1, 3);
    layout_effects->addWidget(check_box_full_fog, 5, 0, 1, 4);
    layout_effects->addWidget(check_box_no_fog, 5, 4, 1, 4);
    layout_effects->addWidget(check_box_see_vase, 5, 8, 1, 4);

    for (int i = 0; i < layout_effects->rowCount(); i++)
        layout_effects->setRowStretch(i, 1);
    for (int i = 0; i < layout_effects->columnCount(); i++)
        layout_effects->setColumnStretch(i, 1);

    // Page 8 : Others

    page_others = new QWidget(this);

    check_box_disable_save_data = new QCheckBox(page_others);
    check_box_disable_save_data->setText(tr("Disable Save Data"));
    check_box_disable_delete_data = new QCheckBox(page_others);
    check_box_disable_delete_data->setText(tr("Disable Delete Data"));

    check_box_running_in_background = new QCheckBox(page_others);
    check_box_running_in_background->setText(tr("Running In Background"));
    check_box_no_pause = new QCheckBox(page_others);
    check_box_no_pause->setText(tr("No Pause"));

    label_debug_mode = new QLabel(page_others);
    label_debug_mode->setText(tr("Debug Mode"));
    combo_box_debug_mode_menu = new QComboBox(page_others);
    combo_box_debug_mode_menu->addItem(tr("Off"));
    combo_box_debug_mode_menu->addItem(tr("Spawning"));
    combo_box_debug_mode_menu->addItem(tr("Music"));
    combo_box_debug_mode_menu->addItem(tr("Memory"));
    combo_box_debug_mode_menu->addItem(tr("Collision"));
    combo_box_debug_mode_menu->setCurrentIndex(0);
    push_button_debug_mode = new QPushButton(page_others);
    push_button_debug_mode->setText(tr("Set"));

    push_button_pak_file = new QPushButton(page_others);
    push_button_pak_file->setText(tr("Open File"));
    line_edit_pak_file = new QLineEdit(page_others);
    line_edit_pak_file->setText("");
    push_button_pak_unpack = new QPushButton(page_others);
    push_button_pak_unpack->setText(tr("Unpack"));

    push_button_pak_dir = new QPushButton(page_others);
    push_button_pak_dir->setText(tr("Open Folder"));
    line_edit_pak_dir = new QLineEdit(page_others);
    line_edit_pak_dir->setText("");
    push_button_pak_pack = new QPushButton(page_others);
    push_button_pak_pack->setText(tr("Pack"));

    layout_others = new QGridLayout(page_others);
    layout_others->addWidget(check_box_disable_save_data, 0, 0, 1, 3);
    layout_others->addWidget(check_box_disable_delete_data, 0, 3, 1, 3);
    layout_others->addWidget(check_box_running_in_background, 0, 6, 1, 3);
    layout_others->addWidget(check_box_no_pause, 0, 9, 1, 3);
    layout_others->addWidget(label_debug_mode, 1, 0, 1, 3);
    layout_others->addWidget(combo_box_debug_mode_menu, 1, 3, 1, 3);
    layout_others->addWidget(push_button_debug_mode, 1, 6, 1, 3);
    layout_others->addWidget(push_button_pak_file, 2, 0, 1, 2);
    layout_others->addWidget(line_edit_pak_file, 2, 2, 1, 8);
    layout_others->addWidget(push_button_pak_unpack, 2, 10, 1, 2);
    layout_others->addWidget(push_button_pak_dir, 3, 0, 1, 2);
    layout_others->addWidget(line_edit_pak_dir, 3, 2, 1, 8);
    layout_others->addWidget(push_button_pak_pack, 3, 10, 1, 2);

    for (int i = 0; i < layout_others->rowCount(); i++)
        layout_others->setRowStretch(i, 1);
    for (int i = 0; i < layout_others->columnCount(); i++)
        layout_others->setColumnStretch(i, 1);

    // Page 9 : Status

    page_status = new QWidget(this);

    timer_status_refresh = new QTimer(page_status);
    timer_status_refresh->setInterval(100);
    label_game_mode_text = new QLabel(page_status);
    label_game_mode_text->setText("");
    check_box_auto_refresh = new QCheckBox(page_status);
    check_box_auto_refresh->setText(tr("Auto Refresh"));
    spin_box_refresh_interval = new QSpinBox(page_status);
    spin_box_refresh_interval->setRange(0, 999999);
    spin_box_refresh_interval->setSingleStep(1);
    spin_box_refresh_interval->setValue(10);

    label_game_mode = new QLabel(page_status);
    label_game_mode->setText(tr("Game Mode"));
    label_game_mode_value = new QLabel(page_status);
    label_game_mode_value->setText("0");
    label_game_ui = new QLabel(page_status);
    label_game_ui->setText(tr("Game UI"));
    label_game_ui_value = new QLabel(page_status);
    label_game_ui_value->setText("0");

    label_running_time = new QLabel(page_status);
    label_running_time->setText(tr("Running Time"));
    label_running_time_value = new QLabel(page_status);
    label_running_time_value->setText("0");
    label_level_completed = new QLabel(page_status);
    label_level_completed->setText(tr("Level Completed"));
    label_level_completed_value = new QLabel(page_status);
    label_level_completed_value->setText("0");

    label_total_waves = new QLabel(page_status);
    label_total_waves->setText(tr("Total Waves"));
    label_total_waves_value = new QLabel(page_status);
    label_total_waves_value->setText("0");
    label_past_waves = new QLabel(page_status);
    label_past_waves->setText(tr("Past Waves"));
    label_past_waves_value = new QLabel(page_status);
    label_past_waves_value->setText("0");

    label_total_hp = new QLabel(page_status);
    label_total_hp->setText(tr("Total HP"));
    label_total_hp_value = new QLabel(page_status);
    label_total_hp_value->setText("0");
    label_trigger_hp = new QLabel(page_status);
    label_trigger_hp->setText(tr("Trigger HP"));
    label_trigger_hp_value = new QLabel(page_status);
    label_trigger_hp_value->setText("0");

    label_countdown = new QLabel(page_status);
    label_countdown->setText(tr("Count Down"));
    label_countdown_value = new QLabel(page_status);
    label_countdown_value->setText("0");
    label_hugewave_countdown = new QLabel(page_status);
    label_hugewave_countdown->setText(tr("Huge Wave Count Down"));
    label_hugewave_countdown_value = new QLabel(page_status);
    label_hugewave_countdown_value->setText("0");

    label_plant_count = new QLabel(page_status);
    label_plant_count->setText(tr("Plant Count"));
    label_plant_count_value = new QLabel(page_status);
    label_plant_count_value->setText("0");
    label_zombie_count = new QLabel(page_status);
    label_zombie_count->setText(tr("Zombie Count"));
    label_zombie_count_value = new QLabel(page_status);
    label_zombie_count_value->setText("0");

    layout_status = new QGridLayout(page_status);
    layout_status->addWidget(label_game_mode_text, 0, 0, 1, 3);
    layout_status->addWidget(check_box_auto_refresh, 0, 3, 1, 2);
    layout_status->addWidget(spin_box_refresh_interval, 0, 5, 1, 1);
    layout_status->addWidget(label_game_mode, 1, 0, 1, 2);
    layout_status->addWidget(label_game_mode_value, 1, 2, 1, 1);
    layout_status->addWidget(label_game_ui, 1, 3, 1, 2);
    layout_status->addWidget(label_game_ui_value, 1, 5, 1, 1);
    layout_status->addWidget(label_running_time, 2, 0, 1, 2);
    layout_status->addWidget(label_running_time_value, 2, 2, 1, 1);
    layout_status->addWidget(label_level_completed, 2, 3, 1, 2);
    layout_status->addWidget(label_level_completed_value, 2, 5, 1, 1);
    layout_status->addWidget(label_total_waves, 3, 0, 1, 2);
    layout_status->addWidget(label_total_waves_value, 3, 2, 1, 1);
    layout_status->addWidget(label_past_waves, 3, 3, 1, 2);
    layout_status->addWidget(label_past_waves_value, 3, 5, 1, 1);
    layout_status->addWidget(label_total_hp, 4, 0, 1, 2);
    layout_status->addWidget(label_total_hp_value, 4, 2, 1, 1);
    layout_status->addWidget(label_trigger_hp, 4, 3, 1, 2);
    layout_status->addWidget(label_trigger_hp_value, 4, 5, 1, 1);
    layout_status->addWidget(label_countdown, 5, 0, 1, 2);
    layout_status->addWidget(label_countdown_value, 5, 2, 1, 1);
    layout_status->addWidget(label_hugewave_countdown, 5, 3, 1, 2);
    layout_status->addWidget(label_hugewave_countdown_value, 5, 5, 1, 1);
    layout_status->addWidget(label_plant_count, 6, 0, 1, 2);
    layout_status->addWidget(label_plant_count_value, 6, 2, 1, 1);
    layout_status->addWidget(label_zombie_count, 6, 3, 1, 2);
    layout_status->addWidget(label_zombie_count_value, 6, 5, 1, 1);

    for (int i = 0; i < layout_status->rowCount(); i++)
        layout_status->setRowStretch(i, 1);
    for (int i = 0; i < layout_status->columnCount(); i++)
        layout_status->setColumnStretch(i, 1);

    // Page 10 : About

    page_about = new QWidget(this);

    label_logo = new QLabel(page_about);
    QImage *image = new QImage(":/res/logo_about.png");
    label_logo->setPixmap(QPixmap::fromImage(*image));

    label_name = new QLabel(page_about);
    label_name->setText(tr("PvZ Tools"));
    label_version = new QLabel(page_about);
    label_version->setText(tr("Version 1.12.1.1315 (2018.03.07)"));
    label_copy = new QLabel(page_about);
    label_copy->setText(tr("Copyright (c) 2018 <a href='https://www.lmintlcx.com/'>lmintlcx</a>"));

    label_license = new QLabel(page_about);
    label_license->setText(tr("Based on PVZ Helper 1.8.7 / Build with Qt 5.6.3"));
    label_contact = new QLabel(page_about);
    label_contact->setText(tr("Contact: <a href='mailto:pvztools@lmintlcx.com'>pvztools@lmintlcx.com</a>"));
    label_website = new QLabel(page_about);
    label_website->setText(tr("Website: <a href='https://github.com/lmintlcx/PvZTools'>https://github.com/lmintlcx/PvZTools</a>"));

    push_button_font = new QPushButton(page_about);
    push_button_font->setText(tr("Font"));
    combo_box_font_size = new QComboBox(page_about);
    combo_box_font_size->addItem(tr("Small"));
    combo_box_font_size->addItem(tr("Medium"));
    combo_box_font_size->addItem(tr("Large"));
    combo_box_font_size->setCurrentIndex(0);
    push_button_find_game = new QPushButton(page_about);
    push_button_find_game->setText(tr("Find Game"));

    // init font size and clickable
    QFont font = QApplication::font();
    font.setPointSize(21);
    font.setBold(true);
    label_name->setFont(font);
    font.setPointSize(11);
    font.setBold(false);
    label_version->setFont(font);
    label_copy->setFont(font);
    label_copy->setOpenExternalLinks(true);
    label_contact->setOpenExternalLinks(true);
    label_website->setOpenExternalLinks(true);

    layout_about = new QGridLayout(page_about);
    layout_about->addWidget(label_logo, 0, 0, 3, 2);
    layout_about->addWidget(label_name, 0, 2, 1, 4);
    layout_about->addWidget(label_version, 1, 2, 1, 4);
    layout_about->addWidget(label_copy, 2, 2, 1, 4);
    layout_about->addWidget(label_license, 3, 0, 1, 6);
    layout_about->addWidget(label_contact, 4, 0, 1, 6);
    layout_about->addWidget(label_website, 5, 0, 1, 6);
    layout_about->addWidget(push_button_font, 6, 0, 1, 1);
    layout_about->addWidget(combo_box_font_size, 6, 1, 1, 1);
    layout_about->addWidget(push_button_find_game, 6, 4, 1, 2);

    for (int i = 0; i < layout_about->rowCount(); i++)
        layout_about->setRowStretch(i, 1);
    for (int i = 0; i < layout_about->columnCount(); i++)
        layout_about->setColumnStretch(i, 1);

    // Main Stacked Widget
    stacked_widget = new QStackedWidget(this);
    stacked_widget->addWidget(page_resources);
    stacked_widget->addWidget(page_level);
    stacked_widget->addWidget(page_plant);
    stacked_widget->addWidget(page_zombie);
    stacked_widget->addWidget(page_spawn);
    stacked_widget->addWidget(page_slots);
    stacked_widget->addWidget(page_scene);
    stacked_widget->addWidget(page_effects);
    stacked_widget->addWidget(page_others);
    stacked_widget->addWidget(page_status);
    stacked_widget->addWidget(page_about);
    stacked_widget->setCurrentIndex(0);

    // Main Layout
    main_layout = new QHBoxLayout(this);
    main_layout->addWidget(list_widget);
    main_layout->addWidget(stacked_widget);
    main_layout->setStretchFactor(list_widget, 1);
    main_layout->setStretchFactor(stacked_widget, 5);
    setLayout(main_layout);

    // Signal and Slots

    // Use connect(sender, &Sender::Signal, pvz, [](){});
    // not connect(sender, &Sender::Signal, this, [](){});
    // to make lambdas not run in ui thread.

    connect(list_widget, &QListWidget::currentRowChanged, stacked_widget, &QStackedWidget::setCurrentIndex);

    connect(thread, &QThread::started, pvz, &PVZ::FindGame);
    connect(pvz, &PVZ::FindResult, this, &MainWindow::FindResult);
    connect(thread, &QThread::finished, pvz, &QObject::deleteLater);
    connect(thread, &QThread::finished, thread, &QObject::deleteLater);

    // Page 0 : Resources

    connect(push_button_sun, &QPushButton::clicked, pvz, [=]() {
        int sun = line_edit_sun->text().toInt();
        pvz->SetSun(sun);
    });

    connect(check_box_sun_limit, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->IncreaseSunLimit((state == Qt::Checked) ? true : false);
    });

    connect(push_button_money, &QPushButton::clicked, pvz, [=]() {
        int money = line_edit_money->text().toInt();
        money /= 10;
        pvz->SetMoney(money);
    });

    connect(check_box_money_limit, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->IncreaseMoneyLimit((state == Qt::Checked) ? true : false);
    });

    connect(check_box_many_falling_sun, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_no_falling_sun->setChecked(false);
            pvz->SetFallingSun(1);
            QTimer::singleShot(7500, this, [=]() {
                pvz->SetFallingSun(0);
                check_box_many_falling_sun->setChecked(false);
            }); // Will FC if there are to many.
        }
        else if (state == Qt::Unchecked && check_box_no_falling_sun->checkState() != Qt::Checked)
            pvz->SetFallingSun(0);
    });

    connect(check_box_no_falling_sun, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_many_falling_sun->setChecked(false);
            pvz->SetFallingSun(2);
        }
        else if (state == Qt::Unchecked && check_box_many_falling_sun->checkState() != Qt::Checked)
            pvz->SetFallingSun(0);
    });

    connect(check_box_auto_collect, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->AutoCollect((state == Qt::Checked) ? true : false);
    });

    connect(timer_coin_disappear, &QTimer::timeout, pvz, &PVZ::CoinDisappear);

    connect(check_box_coin_disappear, &QCheckBox::stateChanged, [=](int state) {
        if (state == Qt::Checked)
            timer_coin_disappear->start();
        else if (state == Qt::Unchecked)
            timer_coin_disappear->stop();
    });

    connect(push_button_height, &QPushButton::clicked, pvz, [=]() {
        int height = line_edit_height->text().toInt();
        pvz->SetTreeHeight(height);
    });

    connect(push_button_all_shop_items, &QPushButton::clicked, pvz, &PVZ::GetAllShopItems);

    connect(check_box_fertilizer_unlimited, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->FertilizerUnlimited((state == Qt::Checked) ? true : false);
    });

    connect(check_box_bug_spray_unlimited, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->BugSprayUnlimited((state == Qt::Checked) ? true : false);
    });

    connect(check_box_chocolate_unlimited, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ChocolateUnlimited((state == Qt::Checked) ? true : false);
    });

    connect(check_box_tree_food_unlimited, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->TreeFoodUnlimited((state == Qt::Checked) ? true : false);
    });

    // Page 1 : Level

    connect(push_button_gold_sunflower_trophy, &QPushButton::clicked, pvz, &PVZ::GetGoldSunflowerTrophy);

    connect(check_box_unlock_all_mode, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->UnlockAllMode((state == Qt::Checked) ? true : false);
    });

    connect(check_box_show_hide_games, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ShowHideGames((state == Qt::Checked) ? true : false);
    });

    connect(push_button_win, &QPushButton::clicked, pvz, &PVZ::Win);

    connect(push_button_jump_level, &QPushButton::clicked, pvz, [=]() {
        int level = line_edit_level->text().toInt();
        pvz->JumpLevel(level);
    });

    connect(combo_box_mixmode_menu, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), stacked_widget_mixmode_choose, &QStackedWidget::setCurrentIndex);

    connect(combo_box_mixmode_minigames, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=](int index) {
        if (index == 22 || index == 27)
            push_button_mixmode->setEnabled(false); // Will crash.
        else
            push_button_mixmode->setEnabled(true);
    });

    connect(push_button_mixmode, &QPushButton::clicked, pvz, [=]() {
        int menu = combo_box_mixmode_menu->currentIndex();
        int level = combo_box_mixmode_adventure->currentIndex() + 1;
        int mode = 0;
        if (menu == 1)
        {
            mode = combo_box_mixmode_minigames->currentIndex();
            mode += 16;
        }
        else if (menu == 2)
        {
            mode = combo_box_mixmode_puzzle->currentIndex();
            mode += 51;
        }
        else if (menu == 3)
        {
            mode = combo_box_mixmode_survival->currentIndex();
            mode += 1;
        }
        pvz->MixMode(mode, level);
    });

    connect(push_button_scene_type, &QPushButton::clicked, pvz, [=]() {
        int scene = combo_box_scene_type->currentIndex();
        pvz->SetScene(scene);
    });

    // Page 2 : Plants

    connect(check_box_cob_cannon_nocd, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->CobCannonNoCD((state == Qt::Checked) ? true : false);
    });

    connect(check_box_magnets_nocd, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->MagnetsNoCD((state == Qt::Checked) ? true : false);
    });

    connect(check_box_potato_mine_nocd, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->PotatoMineNoCD((state == Qt::Checked) ? true : false);
    });

    connect(check_box_chomper_nocd, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ChomperNoCD((state == Qt::Checked) ? true : false);
    });

    connect(check_box_plant_invincible, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_plant_weak->setChecked(false);
            pvz->SetPlantStrength(1);
        }
        else if (state == Qt::Unchecked && check_box_plant_weak->checkState() != Qt::Checked)
            pvz->SetPlantStrength(0);
    });

    connect(check_box_plant_weak, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_plant_invincible->setChecked(false);
            pvz->SetPlantStrength(2);
        }
        else if (state == Qt::Unchecked && check_box_plant_invincible->checkState() != Qt::Checked)
            pvz->SetPlantStrength(0);
    });

    connect(check_box_lock_kernel, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_lock_butter->setChecked(false);
            pvz->LockKernelOrButter(1);
        }
        else if (state == Qt::Unchecked && check_box_lock_butter->checkState() != Qt::Checked)
            pvz->LockKernelOrButter(0);
    });

    connect(check_box_lock_butter, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_lock_kernel->setChecked(false);
            pvz->LockKernelOrButter(2);
        }
        else if (state == Qt::Unchecked && check_box_lock_kernel->checkState() != Qt::Checked)
            pvz->LockKernelOrButter(0);
    });

    connect(check_box_no_crater, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->NoCrater((state == Qt::Checked) ? true : false);
    });

    connect(check_box_mushrooms_awake, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->MushroomsAwake((state == Qt::Checked) ? true : false);
    });

    connect(check_box_strong_blover, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->StrongBlover((state == Qt::Checked) ? true : false);
    });

    connect(check_box_strong_peas, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->StrongPeas((state == Qt::Checked) ? true : false);
    });

    connect(check_box_umbrella, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->Umbrella((state == Qt::Checked) ? true : false);
    });

    connect(check_box_beghouled_free_move, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->BeghouledFreeMove((state == Qt::Checked) ? true : false);
    });

    connect(check_box_produce_speed_up, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ProduceSpeedUp((state == Qt::Checked) ? true : false);
    });

    connect(check_box_attack_speed_up, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->AttackSpeedUp((state == Qt::Checked) ? true : false);
    });

    connect(combo_box_plant_projectile, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=](int index) {
        int damage = pvz->GetDamage(index);
        line_edit_plant_damage->setText(QString::number(damage));
    });

    connect(push_button_plant_damage, &QPushButton::clicked, pvz, [=]() {
        int index = combo_box_plant_projectile->currentIndex();
        int damage = line_edit_plant_damage->text().toInt();
        pvz->SetDamage(index, damage);
    });

    // Page 3 : Zombies

    connect(check_box_zombie_explode_immediately, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_zombie_explode_never->setChecked(false); // Set exclusive.
            pvz->SetZombieExplode(1);
        }
        // When the unchecked status was not triggered by another check box.
        else if (state == Qt::Unchecked && check_box_zombie_explode_never->checkState() != Qt::Checked)
            pvz->SetZombieExplode(0);
    });

    connect(check_box_zombie_explode_never, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_zombie_explode_immediately->setChecked(false);
            pvz->SetZombieExplode(2);
        }
        else if (state == Qt::Unchecked && check_box_zombie_explode_immediately->checkState() != Qt::Checked)
            pvz->SetZombieExplode(0);
    });

    connect(check_box_zombie_invisible, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_zombie_show->setChecked(false);
            pvz->SetZombieVisibility(1);
        }
        else if (state == Qt::Unchecked && check_box_zombie_show->checkState() != Qt::Checked)
            pvz->SetZombieVisibility(0);
    });

    connect(check_box_zombie_show, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_zombie_invisible->setChecked(false);
            pvz->SetZombieVisibility(2);
        }
        else if (state == Qt::Unchecked && check_box_zombie_invisible->checkState() != Qt::Checked)
            pvz->SetZombieVisibility(0);
    });

    connect(check_box_zombie_weak, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_zombie_invincible->setChecked(false);
            pvz->SetZombieStrength(1);
        }
        else if (state == Qt::Unchecked && check_box_zombie_invincible->checkState() != Qt::Checked)
            pvz->SetZombieStrength(0);
    });

    connect(check_box_zombie_invincible, &QCheckBox::stateChanged, pvz, [=](int state) {
        if (state == Qt::Checked)
        {
            check_box_zombie_weak->setChecked(false);
            pvz->SetZombieStrength(2);
        }
        else if (state == Qt::Unchecked && check_box_zombie_weak->checkState() != Qt::Checked)
            pvz->SetZombieStrength(0);
    });

    connect(check_box_stop_spawning, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->StopSpawning((state == Qt::Checked) ? true : false);
    });

    connect(check_box_zombies_no_move, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ZombiesNoMove((state == Qt::Checked) ? true : false);
    });

    connect(check_box_no_ice_slow_down, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->NoIceSlowDown((state == Qt::Checked) ? true : false);
    });

    connect(check_box_no_butter_immobilize, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->NoButterImmobilize((state == Qt::Checked) ? true : false);
    });

    connect(check_box_no_3_zombies_group, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->No3zGroup((state == Qt::Checked) ? true : false);
    });

    connect(check_box_no_ice_trail, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->NoIceTrail((state == Qt::Checked) ? true : false);
    });

    connect(check_box_no_throw_imp, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->NoThrowImp((state == Qt::Checked) ? true : false);
    });

    connect(check_box_gargantuar_eatable, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->GargantuarEatable((state == Qt::Checked) ? true : false);
    });

    connect(check_box_zomboss_no_move, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ZombossNoMove((state == Qt::Checked) ? true : false);
    });

    connect(check_box_balloon_burst, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->BalloonBurst((state == Qt::Checked) ? true : false);
    });

    connect(check_box_gather_zombies, &QCheckBox::stateChanged, pvz, [=](int state) {
        float pos = float(slider_gather_zombies->value());
        pvz->GatherZombies((state == Qt::Checked) ? true : false, pos);
    });

    connect(slider_gather_zombies, &QSlider::valueChanged, pvz, [=](int value) {
        if (check_box_gather_zombies->checkState() == Qt::Checked)
            pvz->GatherZombies(true, value);
    });

    connect(push_button_spawning_all_zombies, &QPushButton::clicked, pvz, &PVZ::SpawningAllZombies);

    connect(push_button_all_zombies, &QPushButton::clicked, pvz, [=]() {
        int zombie_status = combo_box_all_zombies->currentIndex();
        pvz->AllZombiesXXX(zombie_status);
    });

    // Page 4 : Spawn

    connect(push_button_natural_spawn, &QPushButton::clicked, pvz, [=]() {
        bool zombies[33];
        for (int i = 0; i < 33; i++)
            zombies[i] = false;
        zombies[0] = true;
        zombies[2] = check_box_spawn_2->isChecked();
        zombies[3] = check_box_spawn_3->isChecked();
        zombies[4] = check_box_spawn_4->isChecked();
        zombies[5] = check_box_spawn_5->isChecked();
        zombies[6] = check_box_spawn_6->isChecked();
        zombies[7] = check_box_spawn_7->isChecked();
        zombies[8] = check_box_spawn_8->isChecked();
        zombies[11] = check_box_spawn_11->isChecked();
        zombies[12] = check_box_spawn_12->isChecked();
        zombies[14] = check_box_spawn_14->isChecked();
        zombies[15] = check_box_spawn_15->isChecked();
        zombies[16] = check_box_spawn_16->isChecked();
        zombies[17] = check_box_spawn_17->isChecked();
        zombies[18] = check_box_spawn_18->isChecked();
        zombies[19] = check_box_spawn_19->isChecked();
        zombies[20] = check_box_spawn_20->isChecked();
        zombies[21] = check_box_spawn_21->isChecked();
        zombies[22] = check_box_spawn_22->isChecked();
        zombies[23] = check_box_spawn_23->isChecked();
        zombies[32] = check_box_spawn_32->isChecked();
        pvz->InternalSpawn(zombies, false);
    });

    connect(push_button_extreme_spawn, &QPushButton::clicked, pvz, [=]() {
        bool zombies[33];
        for (int i = 0; i < 33; i++)
            zombies[i] = false;
        zombies[0] = true;
        zombies[2] = check_box_spawn_2->isChecked();
        zombies[3] = check_box_spawn_3->isChecked();
        zombies[4] = check_box_spawn_4->isChecked();
        zombies[5] = check_box_spawn_5->isChecked();
        zombies[6] = check_box_spawn_6->isChecked();
        zombies[7] = check_box_spawn_7->isChecked();
        zombies[8] = check_box_spawn_8->isChecked();
        zombies[11] = check_box_spawn_11->isChecked();
        zombies[12] = check_box_spawn_12->isChecked();
        zombies[14] = check_box_spawn_14->isChecked();
        zombies[15] = check_box_spawn_15->isChecked();
        zombies[16] = check_box_spawn_16->isChecked();
        zombies[17] = check_box_spawn_17->isChecked();
        zombies[18] = check_box_spawn_18->isChecked();
        zombies[19] = check_box_spawn_19->isChecked();
        zombies[20] = check_box_spawn_20->isChecked();
        zombies[21] = check_box_spawn_21->isChecked();
        zombies[22] = check_box_spawn_22->isChecked();
        zombies[23] = check_box_spawn_23->isChecked();
        zombies[32] = check_box_spawn_32->isChecked();
        pvz->CustomizeSpawn(zombies, true, true, true, false);
    });

    connect(check_box_detailed_mode, &QCheckBox::stateChanged, [=](int state) {
        if (state == Qt::Checked)
        {
            widget_spawn_brief->setVisible(false);
            push_button_natural_spawn->setVisible(false);
            push_button_extreme_spawn->setVisible(false);
            line_edit_random_seed->setVisible(true);
            push_button_random_seed->setVisible(true);
            combo_box_spawn_menu->setVisible(true);
            push_button_spawn_add->setVisible(true);
            push_button_spawn_delete->setVisible(true);
            push_button_spawn_clear->setVisible(true);
            radio_button_natural_spawn->setVisible(true);
            radio_button_extreme_spawn->setVisible(true);
            check_box_evenly_filled->setVisible(true);
            check_box_limit_yeti->setVisible(true);
            check_box_limit_bungee->setVisible(true);
            check_box_limit_giga->setVisible(true);
            push_button_spawn_original->setVisible(true);
            push_button_spawn_set->setVisible(true);
            list_widget_spawn->setVisible(true);
            int random_seed = pvz->GetRandomSeed();
            if (random_seed != 0)
            {
                QString seed_text = QString("%1").arg(random_seed, 8, 16, QLatin1Char('0')).toUpper();
                line_edit_random_seed->setText(seed_text);
            }
        }
        else if (state == Qt::Unchecked)
        {
            widget_spawn_brief->setVisible(true);
            push_button_natural_spawn->setVisible(true);
            push_button_extreme_spawn->setVisible(true);
            line_edit_random_seed->setVisible(false);
            push_button_random_seed->setVisible(false);
            combo_box_spawn_menu->setVisible(false);
            push_button_spawn_add->setVisible(false);
            push_button_spawn_delete->setVisible(false);
            push_button_spawn_clear->setVisible(false);
            radio_button_natural_spawn->setVisible(false);
            radio_button_extreme_spawn->setVisible(false);
            check_box_evenly_filled->setVisible(false);
            check_box_limit_yeti->setVisible(false);
            check_box_limit_bungee->setVisible(false);
            check_box_limit_giga->setVisible(false);
            push_button_spawn_original->setVisible(false);
            push_button_spawn_set->setVisible(false);
            list_widget_spawn->setVisible(false);
        }
    });

    connect(push_button_random_seed, &QPushButton::clicked, pvz, [=]() {
        bool ok;
        int random_seed = line_edit_random_seed->text().toInt(&ok, 16);
        if (ok)
        {
            pvz->SetRandomSeed(random_seed);
            pvz->InternalSpawn(nullptr, true);
        }
    });

    connect(radio_button_natural_spawn, &QRadioButton::toggled, [=](bool checked) {
        if (checked)
        {
            check_box_evenly_filled->setEnabled(false);
            check_box_limit_yeti->setEnabled(false);
            check_box_limit_bungee->setEnabled(false);
            check_box_limit_giga->setEnabled(false);
        }
    });

    connect(radio_button_extreme_spawn, &QRadioButton::toggled, [=](bool checked) {
        if (checked)
        {
            check_box_evenly_filled->setEnabled(true);
            check_box_limit_yeti->setEnabled(true);
            check_box_limit_bungee->setEnabled(true);
            check_box_limit_giga->setEnabled(true);
        }
    });

    connect(push_button_spawn_add, &QPushButton::clicked, [=]() {
        QString spawn_item = combo_box_spawn_menu->currentText();
        QList<QListWidgetItem *> item_list = list_widget_spawn->findItems(spawn_item, Qt::MatchContains);
        if (item_list.count() == 0)
            list_widget_spawn->addItem(spawn_item);
    });

    connect(push_button_spawn_delete, &QPushButton::clicked, [=]() {
        int row = list_widget_spawn->currentRow();
        if (row != -1)
        {
            QListWidgetItem *item_take = list_widget_spawn->takeItem(row);
            delete item_take;
        }
        list_widget_spawn->setCurrentRow(-1);
    });

    connect(push_button_spawn_clear, &QPushButton::clicked, [=]() {
        list_widget_spawn->clear();
    });

    connect(push_button_spawn_original, &QPushButton::clicked, pvz, [=]() {
        pvz->InternalSpawn(nullptr, true);
    });

    connect(push_button_spawn_set, &QPushButton::clicked, pvz, [=]() {
        bool zombies[33];
        for (int i = 0; i < 33; i++)
            zombies[i] = list_widget_spawn->findItems(list_zombie[i], Qt::MatchContains).count() > 0 ? true : false;
        if (radio_button_natural_spawn->isChecked())
            pvz->InternalSpawn(zombies, false);
        else if (radio_button_extreme_spawn->isChecked())
        {
            bool random = !check_box_evenly_filled->isChecked();
            bool limit_yeti = check_box_limit_yeti->isChecked();
            bool limit_bungee = check_box_limit_bungee->isChecked();
            bool limit_giga = check_box_limit_giga->isChecked();
            pvz->CustomizeSpawn(zombies, random, limit_yeti, limit_bungee, limit_giga);
        }
    });

    // Page 5 : Slots

    connect(push_button_slots_count, &QPushButton::clicked, pvz, [=]() {
        int num = spin_box_slots_count->text().toInt();
        pvz->SetSlotsCount(num);
    });

    connect(push_button_show_shovel, &QPushButton::clicked, pvz, &PVZ::ShowShovel);

    connect(combo_box_slots_seed, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=](int index) {
        if (index >= 53)
            check_box_slots_imitater->setEnabled(false); // Zombies have no imitater.
        else
            check_box_slots_imitater->setEnabled(true);
        if (index == 53 || index == 54 || index == 55 || index == 56 || index == 57 || index == 75)
            push_button_slots_set->setEnabled(false); // Will crash.
        else
            push_button_slots_set->setEnabled(true);

    });

    connect(push_button_slots_set, &QPushButton::clicked, pvz, [=]() {
        int slot = combo_box_slots_slot->currentIndex();
        int type = combo_box_slots_seed->currentIndex();
        bool imitater = check_box_slots_imitater->isChecked();
        pvz->SetSlotsSeed(slot, type, imitater);
    });

    connect(check_box_slots_purple_seed_unlimited, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->PurpleSeedUnlimited((state == Qt::Checked) ? true : false);
    });

    connect(check_box_planting_freely, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->PlantingFreely((state == Qt::Checked) ? true : false);
    });

    connect(check_box_slots_belt_no_delay, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->BeltNoDelay((state == Qt::Checked) ? true : false);
    });

    connect(check_box_lock_shovel, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->LockShovel((state == Qt::Checked) ? true : false);
    });

    connect(combo_box_seed, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=](int index) {
        if (pvz->GameOn())
        {
            int speed = pvz->GetSpeed(index);
            int cost = pvz->GetCost(index);
            int recharge = pvz->GetRecharge(index);
            line_edit_seed_speed->setText(QString::number(speed));
            line_edit_seed_cost->setText(QString::number(cost));
            line_edit_seed_recharge->setText(QString::number(recharge));
        }
    });

    connect(check_box_ignore_sun, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->IgnoreSun((state == Qt::Checked) ? true : false);
    });

    connect(check_box_slots_no_cool_down, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->SlotsNoCoolDown((state == Qt::Checked) ? true : false);
    });

    connect(push_button_seed_speed, &QPushButton::clicked, pvz, [=]() {
        int index = combo_box_seed->currentIndex();
        int speed = line_edit_seed_speed->text().toInt();
        pvz->SetSpeed(index, speed);
    });

    connect(push_button_seed_cost, &QPushButton::clicked, pvz, [=]() {
        int index = combo_box_seed->currentIndex();
        int cost = line_edit_seed_cost->text().toInt();
        pvz->SetCost(index, cost);
    });

    connect(push_button_seed_recharge, &QPushButton::clicked, pvz, [=]() {
        int index = combo_box_seed->currentIndex();
        int recharge = line_edit_seed_recharge->text().toInt();
        pvz->SetRecharge(index, recharge);
    });

    // Page 6 : Scene

    connect(push_button_put_plant, &QPushButton::clicked, pvz, [=]() {
        int row = spin_box_scene_row->text().toInt() - 1;
        int col = spin_box_scene_col->text().toInt() - 1;
        int type = combo_box_plant_menu->currentIndex();
        bool imitater = check_box_plant_imitater->isChecked() || type == 48;
        pvz->Plant(row, col, type, imitater);
    });

    connect(push_button_put_zombie, &QPushButton::clicked, pvz, [=]() {
        int row = spin_box_scene_row->text().toInt() - 1;
        int col = spin_box_scene_col->text().toInt() - 1;
        int type = combo_box_zombie_menu->currentIndex();
        pvz->PutZombie(row, col, type);
    });

    connect(push_button_put_grave, &QPushButton::clicked, pvz, [=]() {
        int row = spin_box_scene_row->text().toInt() - 1;
        int col = spin_box_scene_col->text().toInt() - 1;
        pvz->PutGrave(row, col);
    });

    connect(push_button_put_ladder, &QPushButton::clicked, pvz, [=]() {
        int row = spin_box_scene_row->text().toInt() - 1;
        int col = spin_box_scene_col->text().toInt() - 1;
        pvz->PutLadder(row, col);
    });

    connect(push_button_auto_ladder, &QPushButton::clicked, pvz, [=]() {
        bool imitater_pumpkin_only = check_box_imitater_pumpkin_only->isChecked();
        pvz->AutoLadder(imitater_pumpkin_only);
    });

    connect(push_button_eat_all_graves, &QPushButton::clicked, pvz, &PVZ::EatAllGraves);

    connect(push_button_lily_pad_on_pool, &QPushButton::clicked, pvz, &PVZ::LilyPadOnPool);

    connect(push_button_flower_pot_on_roof, &QPushButton::clicked, pvz, &PVZ::FlowerPotOnRoof);

    connect(push_button_clear_all_plants, &QPushButton::clicked, pvz, &PVZ::ClearAllPlants);

    connect(push_button_block_type, &QPushButton::clicked, pvz, [=]() {
        int row = spin_box_scene_row->text().toInt() - 1;
        int col = spin_box_scene_col->text().toInt() - 1;
        int type = combo_box_block_type->currentIndex() + 1;
        pvz->SetBlock(row, col, type);
    });

    connect(combo_box_scene_row, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=](int index) {
        if (index != 0)
        {
            int row = index - 1;
            int type = pvz->GetRow(row);
            combo_box_row_type->setCurrentIndex(type);
        }
    });

    connect(push_button_row_type, &QPushButton::clicked, pvz, [=]() {
        int row = combo_box_scene_row->currentIndex() - 1;
        int type = combo_box_row_type->currentIndex();
        pvz->SetRow(row, type);
    });

    connect(push_button_start_lawn_mowers, &QPushButton::clicked, pvz, [=]() {
        pvz->StartLawnMowers();
    });

    connect(push_button_reset_lawn_mowers, &QPushButton::clicked, pvz, [=]() {
        pvz->ResetLawnMowers();
    });

    // Page 7 : Effects

    connect(push_button_code_sukhbir, &QPushButton::clicked, pvz, [=]() {
        pvz->WisdomTreeCode(0);
    });

    connect(push_button_code_future, &QPushButton::clicked, pvz, [=]() {
        pvz->WisdomTreeCode(5);
    });

    connect(push_button_code_mustache, &QPushButton::clicked, pvz, [=]() {
        pvz->WisdomTreeCode(20);
    });

    connect(push_button_code_trickedout, &QPushButton::clicked, pvz, [=]() {
        pvz->WisdomTreeCode(48);
    });

    connect(push_button_code_daisies, &QPushButton::clicked, pvz, [=]() {
        pvz->WisdomTreeCode(99);
    });

    connect(push_button_code_dance, &QPushButton::clicked, pvz, [=]() {
        pvz->WisdomTreeCode(500);
    });

    connect(push_button_code_pinata, &QPushButton::clicked, pvz, [=]() {
        pvz->WisdomTreeCode(999);
    });

    connect(push_button_code_konami, &QPushButton::clicked, pvz, [=]() {
        pvz->KonamiCode();
    });

    connect(check_box_effect_little_zombie, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->LittleZombie((state == Qt::Checked) ? true : false);
    });

    connect(check_box_effect_its_raining, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ItsRaining((state == Qt::Checked) ? true : false);
    });

    connect(check_box_effect_stormy_night, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->StormyNight((state == Qt::Checked) ? true : false);
    });

    connect(check_box_effect_high_gravity, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->HighGravity((state == Qt::Checked) ? true : false);
    });

    connect(check_box_effect_column_like, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ColumnLike((state == Qt::Checked) ? true : false);
    });

    connect(check_box_effect_zombie_quick, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->ZombieQuick((state == Qt::Checked) ? true : false);
    });

    connect(combo_box_ice_trail_x, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=](int index) {
        if (index == 0)
            line_edit_ice_trail_x->setText("0");
        else
        {
            int row = index - 1;
            int x = pvz->GetIceTrailX(row);
            line_edit_ice_trail_x->setText(QString::number(x));
        }
    });

    connect(push_button_ice_trail_x, &QPushButton::clicked, pvz, [=]() {
        int row = combo_box_ice_trail_x->currentIndex() - 1;
        int x = line_edit_ice_trail_x->text().toInt();
        pvz->SetIceTrailX(row, x);
    });

    connect(check_box_full_fog, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->FullFog((state == Qt::Checked) ? true : false);
    });

    connect(check_box_no_fog, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->NoFog((state == Qt::Checked) ? true : false);
    });

    connect(check_box_see_vase, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->SeeVase((state == Qt::Checked) ? true : false);
    });

    // Page 8 : Others

    connect(check_box_disable_save_data, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->DisableSaveData((state == Qt::Checked) ? true : false);
    });

    connect(check_box_disable_delete_data, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->DisableDeleteData((state == Qt::Checked) ? true : false);
    });

    connect(check_box_running_in_background, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->RunningInBackground((state == Qt::Checked) ? true : false);
    });

    connect(check_box_no_pause, &QCheckBox::stateChanged, pvz, [=](int state) {
        pvz->NoPause((state == Qt::Checked) ? true : false);
    });

    connect(push_button_debug_mode, &QPushButton::clicked, pvz, [=]() {
        int mode = combo_box_debug_mode_menu->currentIndex();
        pvz->DebugMode(mode);
    });

    connect(push_button_pak_file, &QPushButton::clicked, [=]() {
        QString file_name = QFileDialog::getOpenFileName(
            this,
            tr("Open File"),
            ".",
            tr("PAK files (*.pak) ;; All files (*.*)"));
        if (!file_name.isNull())
        {
            line_edit_pak_file->setText(file_name);
            line_edit_pak_dir->setText(QCoreApplication::applicationDirPath() + "/" + QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
        }
    });

    connect(push_button_pak_dir, &QPushButton::clicked, [=]() {
        QString dir_name = QFileDialog::getExistingDirectory(
            this,
            tr("Open Folder"),
            ".");
        if (!dir_name.isNull())
            line_edit_pak_dir->setText(dir_name);
    });

    connect(push_button_pak_unpack, &QPushButton::clicked, [=]() {
        QString file_name = line_edit_pak_file->text();
        QString dir_name = line_edit_pak_dir->text();
        if (file_name.size() > 0 && dir_name.size() > 0)
        {
            push_button_pak_unpack->setEnabled(false);
            push_button_pak_pack->setEnabled(false);
            emit UnpackPAK(file_name, dir_name);
        }
    });

    connect(push_button_pak_pack, &QPushButton::clicked, [=]() {
        QString dir_name = line_edit_pak_dir->text();
        if (dir_name.size() > 0)
        {
            push_button_pak_unpack->setEnabled(false);
            push_button_pak_pack->setEnabled(false);
            emit PackPAK(dir_name);
        }
    });

    connect(this, &MainWindow::UnpackPAK, pvz, &PVZ::UnpackPAK);
    connect(this, &MainWindow::PackPAK, pvz, &PVZ::PackPAK);

    connect(pvz, &PVZ::PackOrUnpackFinished, this, [=]() {
        push_button_pak_unpack->setEnabled(true);
        push_button_pak_pack->setEnabled(true);
        line_edit_pak_file->setEnabled(true);
        line_edit_pak_dir->setEnabled(true);
    });

    // Page 9 : Status

    connect(check_box_auto_refresh, &QCheckBox::stateChanged, [=](int state) {
        if (state == Qt::Checked)
            timer_status_refresh->start();
        else
            timer_status_refresh->stop();
    });

    connect(list_widget, &QListWidget::currentRowChanged, [=](int row) {
        if (check_box_auto_refresh->isChecked())
        {
            if (row == 9)
                timer_status_refresh->start();
            else
                timer_status_refresh->stop();
        }
    });

    connect(timer_status_refresh, &QTimer::timeout, [=]() {
        if (pvz->GameOn())
        {
            int mode = pvz->GameMode();
            if (mode == 0)
                label_game_mode_text->setText(tr("Adventure"));
            else if (mode >= 1 && mode <= 15)
                label_game_mode_text->setText(list_survival[mode - 1]);
            else if (mode >= 16 && mode <= 50)
                label_game_mode_text->setText(list_minigames[mode - 16]);
            else if (mode >= 51 && mode <= 72)
                label_game_mode_text->setText(list_puzzle[mode - 51]);

            label_game_mode_value->setText(QString::number(pvz->GameMode()));
            label_game_ui_value->setText(QString::number(pvz->GameUI()));
            label_running_time_value->setText(QString::number(pvz->RunningTime()));
            label_level_completed_value->setText(QString::number(pvz->LevelCompleted()));
            label_total_waves_value->setText(QString::number(pvz->TotalWaves()));
            label_past_waves_value->setText(QString::number(pvz->PastWaves()));
            label_total_hp_value->setText(QString::number(pvz->TotalHP()));
            label_trigger_hp_value->setText(QString::number(pvz->TriggerHP()));
            label_countdown_value->setText(QString::number(pvz->CountDown()));
            label_hugewave_countdown_value->setText(QString::number(pvz->HugeWaveCountDown()));
            label_plant_count_value->setText(QString::number(pvz->PlantCount()));
            label_zombie_count_value->setText(QString::number(pvz->ZombieCount()));
        }
        else
        {
            timer_status_refresh->stop();

            label_game_mode_text->setText("");
            label_game_mode_value->setText("0");
            label_game_ui_value->setText("0");
            label_running_time_value->setText("0");
            label_level_completed_value->setText("0");
            label_total_waves_value->setText("0");
            label_past_waves_value->setText("0");
            label_total_hp_value->setText("0");
            label_trigger_hp_value->setText("0");
            label_countdown_value->setText("0");
            label_hugewave_countdown_value->setText("0");
            label_plant_count_value->setText("0");
            label_zombie_count_value->setText("0");
        }
    });

    connect(spin_box_refresh_interval, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), [=](int value) {
        timer_status_refresh->setInterval(value * 10);
    });

    // Page 10 : About

    connect(push_button_font, &QPushButton::clicked, [=]() {
        bool ok;
        QFont font = QFontDialog::getFont(&ok, this);
        if (ok)
            QApplication::setFont(font);
    });

    connect(combo_box_font_size, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), [=](int index) {
        int font_size;
        switch (index)
        {
        case 0:
            font_size = 9;
            break;
        case 1:
            font_size = 10;
            break;
        case 2:
            font_size = 11;
            break;
        }
        QFont font = QApplication::font();
        font.setPointSize(font_size);
        QApplication::setFont(font);
    });

    connect(push_button_find_game, &QPushButton::clicked, pvz, &PVZ::FindGame);

    // ...
    thread->start();
}

MainWindow::~MainWindow()
{
    thread->quit();
    thread->wait();
}

void MainWindow::FindResult(int result)
{
    if (result == -1)
    {
        timer_coin_disappear->stop();
        timer_status_refresh->stop();
        check_box_auto_refresh->setChecked(false);

        QMessageBox msg_box;
        msg_box.setWindowTitle(tr("Warning"));
        msg_box.setIcon(QMessageBox::Warning);
        msg_box.setText(tr("Game Not Found!"));
        msg_box.exec();
    }
    else if (result == 0)
    {
        QMessageBox msg_box;
        msg_box.setWindowTitle(tr("Warning"));
        msg_box.setIcon(QMessageBox::Warning);
        msg_box.setText(tr("Unsupported Game Version!"));
        msg_box.exec();
    }
    // else if (result == 1) {} // OK!
}
