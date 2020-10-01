
#include <QWidget>
#include <QStackedWidget>
#include <QListWidget>
#include <QGridLayout>
#include <QString>
#include <QTimer>
#include <QDebug>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QComboBox>
#include <QSpacerItem>
#include <QPlainTextEdit>
#include <QTextBrowser>
#include <QDesktopServices>
#include <QMessageBox>
#include <QFileDialog>
#include <QCoreApplication>
#include <QApplication>
#include <QDateTime>
#include <QClipboard>
#include <QTableWidget>
#include <QHeaderView>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QUrl>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QSettings>
#include <QUuid>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QInputDialog>
#include <QAction>
#include <QMenu>

#include <QtZlib/zlib.h>

#include <array>
#include <functional>

#include "src/list.h"
#include "src/pages.h"
#include "src/version.h"

namespace Pt
{

// void SET_COMBO_TEXT(QComboBox *, QStringList, unsigned int);
// void SET_COMBO_TEXT(QComboBox *combo, QStringList list, unsigned int size)
// {
//     if (combo->count() == 0)
//         for (size_t i = 0; i < size; i++)
//             combo->addItem(list[i]);
//     else
//         for (size_t i = 0; i < size; i++)
//             combo->setItemText(i, list[i]);
// }

#define SET_COMBO_TEXT(combo, list, size) \
    if (combo->count() == 0)              \
        for (size_t i = 0; i < size; i++) \
            combo->addItem(list[i]);      \
    else                                  \
        for (size_t i = 0; i < size; i++) \
            combo->setItemText(i, list[i]);

// Level

LevelPage::LevelPage(QWidget *parent)
    : QWidget(parent)
{
    getGoldSunflowerTrophyButton = new QPushButton(this);
    getAllShopItemsButton = new QPushButton(this);
    unlockAllModeCheckBox = new QCheckBox(this);
    directWinButton = new QPushButton(this);

    adventureRadioButton = new QRadioButton(this);
    miniGamesRadioButton = new QRadioButton(this);
    puzzleRadioButton = new QRadioButton(this);
    survivalRadioButton = new QRadioButton(this);

    adventureCombo = new QComboBox(this);
    miniGamesCombo = new QComboBox(this);
    puzzleCombo = new QComboBox(this);
    survivalCombo = new QComboBox(this);

    mixmodeButton = new QPushButton(this);

    showHiddenGamesCheckBox = new QCheckBox(this);

    izeArrayCombo = new QComboBox(this);
    lockIzeArrayCheckBox = new QCheckBox(this);

    levelLineEdit = new QLineEdit(this);
    levelLineEdit->setValidator(new QIntValidator(-1, 999999999, this));
    levelLineEdit->setAlignment(Qt::AlignRight);
    jumpLevelButton = new QPushButton(this);

    // set default status

    // adventureRadioButton->setChecked(false);
    // miniGamesRadioButton->setChecked(false);
    // puzzleRadioButton->setChecked(false);
    survivalRadioButton->setChecked(true);

    adventureCombo->setEnabled(false);
    miniGamesCombo->setEnabled(false);
    puzzleCombo->setEnabled(false);
    // survivalCombo->setEnabled(true);

    showHiddenGamesCheckBox->setChecked(true);

    levelLineEdit->setText("1009");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(getGoldSunflowerTrophyButton, 0, 0, 1, 1);
    mainLayout->addWidget(getAllShopItemsButton, 0, 1, 1, 1);
    mainLayout->addWidget(unlockAllModeCheckBox, 0, 2, 1, 2);
    mainLayout->addWidget(directWinButton, 0, 4, 1, 1);
    mainLayout->addWidget(adventureRadioButton, 1, 0, 1, 1);
    mainLayout->addWidget(miniGamesRadioButton, 2, 0, 1, 1);
    mainLayout->addWidget(puzzleRadioButton, 3, 0, 1, 1);
    mainLayout->addWidget(survivalRadioButton, 4, 0, 1, 1);
    mainLayout->addWidget(adventureCombo, 1, 1, 1, 1);
    mainLayout->addWidget(miniGamesCombo, 2, 1, 1, 2);
    mainLayout->addWidget(puzzleCombo, 3, 1, 1, 2);
    mainLayout->addWidget(survivalCombo, 4, 1, 1, 2);
    mainLayout->addWidget(mixmodeButton, 1, 4, 1, 1);
    mainLayout->addWidget(showHiddenGamesCheckBox, 2, 3, 1, 2);
    mainLayout->addWidget(izeArrayCombo, 3, 3, 1, 1);
    mainLayout->addWidget(lockIzeArrayCheckBox, 3, 4, 1, 1);
    mainLayout->addWidget(levelLineEdit, 4, 3, 1, 1);
    mainLayout->addWidget(jumpLevelButton, 4, 4, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(getGoldSunflowerTrophyButton, &QPushButton::clicked,
            this, &LevelPage::GetGoldSunflowerTrophy);

    connect(getAllShopItemsButton, &QPushButton::clicked,
            this, &LevelPage::GetAllShopItems);

    connect(unlockAllModeCheckBox, &QCheckBox::clicked,
            this, &LevelPage::UnlockAllMode);

    connect(directWinButton, &QPushButton::clicked,
            this, &LevelPage::DirectWin);

    connect(adventureRadioButton, &QRadioButton::toggled,
            adventureCombo, &QComboBox::setEnabled);

    connect(miniGamesRadioButton, &QRadioButton::toggled,
            miniGamesCombo, &QComboBox::setEnabled);

    connect(puzzleRadioButton, &QRadioButton::toggled,
            puzzleCombo, &QComboBox::setEnabled);

    connect(survivalRadioButton, &QRadioButton::toggled,
            survivalCombo, &QComboBox::setEnabled);

    connect(mixmodeButton, &QPushButton::clicked,
            this, [=]() {
                // Adventure  // 0
                // Mini-Games // 16-50
                // Puzzle     // 51-72
                // Survival   // 1-15
                int mode;

                if (miniGamesRadioButton->isChecked())
                    mode = miniGamesCombo->currentIndex() + 16;
                else if (puzzleRadioButton->isChecked())
                    mode = puzzleCombo->currentIndex() + 51;
                else if (survivalRadioButton->isChecked())
                    mode = survivalCombo->currentIndex() + 1;
                else
                    mode = 0;

                int level = adventureCombo->currentIndex() + 1;

                emit MixMode(mode, level);
            });

    connect(showHiddenGamesCheckBox, &QCheckBox::clicked,
            this, &LevelPage::ShowHiddenGames);

    connect(izeArrayCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                bool on = lockIzeArrayCheckBox->isChecked();
                int mode = index;
                emit LockIZE(on, mode);
            });

    connect(lockIzeArrayCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                bool on = checked;
                int mode = izeArrayCombo->currentIndex();
                emit LockIZE(on, mode);
            });

    connect(jumpLevelButton, &QPushButton::clicked,
            this, [=]() {
                int level = levelLineEdit->text().toInt();
                emit JumpLevel(level);
            });
}

void LevelPage::TranslateUI()
{
    getGoldSunflowerTrophyButton->setText(tr("Get Gold Sunflower Trophy"));
    getAllShopItemsButton->setText(tr("Get All Shop Items"));
    unlockAllModeCheckBox->setText(tr("Unlock All Mode Temporarily"));
    directWinButton->setText(tr("Direct Win"));

    getGoldSunflowerTrophyButton->setStatusTip(tr("Switch to another game interface (like help) and return to view results after the operation is done."));
    getAllShopItemsButton->setStatusTip(tr("Switch to another game interface (like help) and return to view results after the operation is done."));
    unlockAllModeCheckBox->setStatusTip(tr("Switch to another game interface (like help) and return to view results after the operation is done."));

    adventureRadioButton->setText(tr("Adventure"));
    miniGamesRadioButton->setText(tr("Mini-Games"));
    puzzleRadioButton->setText(tr("Puzzle"));
    survivalRadioButton->setText(tr("Survival"));

    // SET_COMBO_TEXT(adventureCombo, List::Get().adventureList, 50);
    // SET_COMBO_TEXT(miniGamesCombo, List::Get().miniGamesList, 35);
    // SET_COMBO_TEXT(puzzleCombo, List::Get().puzzleList, 22);
    // SET_COMBO_TEXT(survivalCombo, List::Get().survivalList, 15);

    if (adventureCombo->count() == 0)
        for (size_t i = 0; i < 50; i++)
            adventureCombo->addItem(QString("[0]") + " " + List::Get().adventureList[i]);
    else
        for (size_t i = 0; i < 50; i++)
            adventureCombo->setItemText(i, QString("[0]") + " " + List::Get().adventureList[i]);

    if (miniGamesCombo->count() == 0)
        for (size_t i = 0; i < 35; i++)
            miniGamesCombo->addItem(QString("[") + QString::number(i + 16) + "]" + " " + List::Get().miniGamesList[i]);
    else
        for (size_t i = 0; i < 35; i++)
            miniGamesCombo->setItemText(i, QString("[") + QString::number(i + 16) + "]" + " " + List::Get().miniGamesList[i]);

    if (puzzleCombo->count() == 0)
        for (size_t i = 0; i < 22; i++)
            puzzleCombo->addItem(QString("[") + QString::number(i + 51) + "]" + " " + List::Get().puzzleList[i]);
    else
        for (size_t i = 0; i < 22; i++)
            puzzleCombo->setItemText(i, QString("[") + QString::number(i + 51) + "]" + " " + List::Get().puzzleList[i]);

    if (survivalCombo->count() == 0)
        for (size_t i = 0; i < 15; i++)
            survivalCombo->addItem(QString("[") + QString::number(i + 1) + "]" + " " + List::Get().survivalList[i]);
    else
        for (size_t i = 0; i < 15; i++)
            survivalCombo->setItemText(i, QString("[") + QString::number(i + 1) + "]" + " " + List::Get().survivalList[i]);

    mixmodeButton->setText(tr("Mix Mode"));

    showHiddenGamesCheckBox->setText(tr("Show Hidden Games"));

    SET_COMBO_TEXT(izeArrayCombo, List::Get().izeArrayList, 8);
    lockIzeArrayCheckBox->setText(tr("Lock IZE Array"));

    jumpLevelButton->setText(tr("Jump Level"));
}

void LevelPage::KeepSelectedFeatures()
{
    if (unlockAllModeCheckBox->isChecked())
        emit UnlockAllMode(true);

    if (showHiddenGamesCheckBox->isChecked())
        emit ShowHiddenGames(true);

    if (lockIzeArrayCheckBox->isChecked())
    {
        int mode = izeArrayCombo->currentIndex();
        emit LockIZE(true, mode);
    }
}

// Resources

ResourcePage::ResourcePage(QWidget *parent)
    : QWidget(parent)
{
    sunLabel = new QLabel(this);
    sunLineEdit = new QLineEdit(this);
    sunLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    sunLineEdit->setAlignment(Qt::AlignRight);
    sunButton = new QPushButton(this);

    sunLimitLabel = new QLabel(this);
    sunLimitLineEdit = new QLineEdit(this);
    sunLimitLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    sunLimitLineEdit->setAlignment(Qt::AlignRight);
    sunLimitButton = new QPushButton(this);

    moneyLabel = new QLabel(this);
    moneyLineEdit = new QLineEdit(this);
    moneyLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    moneyLineEdit->setAlignment(Qt::AlignRight);
    moneyButton = new QPushButton(this);

    moneyLimitLabel = new QLabel(this);
    moneyLimitLineEdit = new QLineEdit(this);
    moneyLimitLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    moneyLimitLineEdit->setAlignment(Qt::AlignRight);
    moneyLimitButton = new QPushButton(this);

    manyFallingSunCheckBox = new QCheckBox(this);
    noFallingSunCheckBox = new QCheckBox(this);
    autoCollectCheckBox = new QCheckBox(this);
    zombieNoFallingCheckBox = new QCheckBox(this);

    manyFallingSunCheckBox->setEnabled(false);

    valueLabel = new QLabel(this);
    valueCombo = new QComboBox(this);
    valueLineEdit = new QLineEdit(this);
    valueLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    valueLineEdit->setAlignment(Qt::AlignRight);
    valueButton = new QPushButton(this);

    damageLabel = new QLabel(this);
    damageCombo = new QComboBox(this);
    damageLineEdit = new QLineEdit(this);
    damageLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    damageLineEdit->setAlignment(Qt::AlignRight);
    damageButton = new QPushButton(this);

    hpLabel = new QLabel(this);
    hpCombo = new QComboBox(this);
    hpLineEdit = new QLineEdit(this);
    hpLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    hpLineEdit->setAlignment(Qt::AlignRight);
    hpButton = new QPushButton(this);

    timeLabel = new QLabel(this);
    timeCombo = new QComboBox(this);
    timeLineEdit = new QLineEdit(this);
    timeLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    timeLineEdit->setAlignment(Qt::AlignRight);
    timeButton = new QPushButton(this);

    sunLineEdit->setText("8000");
    sunLimitLineEdit->setText("9990");

    moneyLineEdit->setText("80000");
    moneyLimitLineEdit->setText("99999");

    valueLineEdit->setText("");
    damageLineEdit->setText("");
    hpLineEdit->setText("");
    timeLineEdit->setText("");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(sunLabel, 0, 0, 1, 2);
    mainLayout->addWidget(sunLineEdit, 0, 2, 1, 2);
    mainLayout->addWidget(sunButton, 0, 4, 1, 2);
    mainLayout->addWidget(sunLimitLabel, 0, 6, 1, 2);
    mainLayout->addWidget(sunLimitLineEdit, 0, 8, 1, 2);
    mainLayout->addWidget(sunLimitButton, 0, 10, 1, 2);
    mainLayout->addWidget(moneyLabel, 1, 0, 1, 2);
    mainLayout->addWidget(moneyLineEdit, 1, 2, 1, 2);
    mainLayout->addWidget(moneyButton, 1, 4, 1, 2);
    mainLayout->addWidget(moneyLimitLabel, 1, 6, 1, 2);
    mainLayout->addWidget(moneyLimitLineEdit, 1, 8, 1, 2);
    mainLayout->addWidget(moneyLimitButton, 1, 10, 1, 2);
    mainLayout->addWidget(manyFallingSunCheckBox, 2, 10, 1, 2);
    mainLayout->addWidget(noFallingSunCheckBox, 3, 10, 1, 2);
    mainLayout->addWidget(autoCollectCheckBox, 4, 10, 1, 2);
    mainLayout->addWidget(zombieNoFallingCheckBox, 5, 10, 1, 2);
    mainLayout->addWidget(valueLabel, 2, 0, 1, 2);
    mainLayout->addWidget(valueCombo, 2, 2, 1, 3);
    mainLayout->addWidget(valueLineEdit, 2, 5, 1, 2);
    mainLayout->addWidget(valueButton, 2, 7, 1, 2);
    mainLayout->addWidget(damageLabel, 3, 0, 1, 2);
    mainLayout->addWidget(damageCombo, 3, 2, 1, 3);
    mainLayout->addWidget(damageLineEdit, 3, 5, 1, 2);
    mainLayout->addWidget(damageButton, 3, 7, 1, 2);
    mainLayout->addWidget(hpLabel, 4, 0, 1, 2);
    mainLayout->addWidget(hpCombo, 4, 2, 1, 3);
    mainLayout->addWidget(hpLineEdit, 4, 5, 1, 2);
    mainLayout->addWidget(hpButton, 4, 7, 1, 2);
    mainLayout->addWidget(timeLabel, 5, 0, 1, 2);
    mainLayout->addWidget(timeCombo, 5, 2, 1, 3);
    mainLayout->addWidget(timeLineEdit, 5, 5, 1, 2);
    mainLayout->addWidget(timeButton, 5, 7, 1, 2);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(manyFallingSunCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    noFallingSunCheckBox->setChecked(false);
            });

    connect(noFallingSunCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    manyFallingSunCheckBox->setChecked(false);
            });

    connect(autoCollectCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    manyFallingSunCheckBox->setEnabled(true);
                else
                {
                    manyFallingSunCheckBox->setEnabled(false);
                    manyFallingSunCheckBox->setChecked(false);
                }
            });

    connect(sunButton, &QPushButton::clicked,
            this, [=]() {
                int sun = sunLineEdit->text().toInt();
                emit SetSun(sun);
            });

    connect(sunLimitButton, &QPushButton::clicked,
            this, [=]() {
                int sun_limit = sunLimitLineEdit->text().toInt();
                emit SetSunLimit(sun_limit);
            });

    connect(moneyButton, &QPushButton::clicked,
            this, [=]() {
                int money = moneyLineEdit->text().toInt();
                emit SetMoney(money);
            });

    connect(moneyLimitButton, &QPushButton::clicked,
            this, [=]() {
                int money_limit = moneyLimitLineEdit->text().toInt();
                emit SetMoneyLimit(money_limit);
            });

    connect(manyFallingSunCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    emit SetFallingSun(Sun::Many);
                else
                    emit SetFallingSun(Sun::Normal);
            });

    connect(noFallingSunCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetFallingSun(Sun::None);
                else
                    emit SetFallingSun(Sun::Normal);
            });

    connect(autoCollectCheckBox, &QCheckBox::clicked,
            this, &ResourcePage::AutoCollect);

    connect(zombieNoFallingCheckBox, &QCheckBox::clicked,
            this, &ResourcePage::ZombieNoFalling);

    // 0 x10
    // 1 0<=x<=127 +2x10
    // 2 0<=x<=127 x10
    // 3
    // 4 0<=x<=127 +5
    // 5 0<=x<=127

    connect(valueCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                if (index == 0 || index == 2)
                    valueLabel->setText(tr("Value") + " x10");
                else if (index == 1)
                    valueLabel->setText(tr("Value") + " +2 x10");
                else if (index == 4)
                    valueLabel->setText(tr("Value") + " +5");
                else
                    valueLabel->setText(tr("Value"));

                emit GetValue(index);
            });

    connect(valueButton, &QPushButton::clicked,
            this, [=]() {
                int index = valueCombo->currentIndex();
                int value = valueLineEdit->text().toInt();

                // char limit
                if ((index != 0 && index != 3) && value > 127)
                {
                    valueLineEdit->setText("127");
                    value = 127;
                }

                emit SetValue(index, value);
            });

    connect(damageCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                if (index == 17)
                    damageLabel->setText(tr("Damage") + " /4cs");
                else
                    damageLabel->setText(tr("Damage"));

                emit GetDamage(index);
            });

    connect(damageButton, &QPushButton::clicked,
            this, [=]() {
                int index = damageCombo->currentIndex();
                int damage = damageLineEdit->text().toInt();

                // char limit
                if (index == 15 && damage > 127)
                {
                    damageLineEdit->setText("127");
                    damage = 127;
                }
                if (index == 17 && damage > 128)
                {
                    damageLineEdit->setText("128");
                    damage = 128;
                }

                emit SetDamage(index, damage);
            });

    connect(hpCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                std::vector<int> accessories = {7, 9, 10, 11, 12, 17, 21, 25, 27, 30};
                if (std::find(accessories.begin(), accessories.end(), index) != accessories.end())
                    hpLabel->setText(tr("HP") + " " + "(" + tr("Accessories") + ")");
                else
                    hpLabel->setText(tr("HP"));

                emit GetHP(index);
            });

    connect(hpButton, &QPushButton::clicked,
            this, [=]() {
                int index = hpCombo->currentIndex();
                int hp = hpLineEdit->text().toInt();
                emit SetHP(index, hp);
            });

    connect(timeCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &ResourcePage::GetTime);

    connect(timeButton, &QPushButton::clicked,
            this, [=]() {
                int index = timeCombo->currentIndex();
                int t = timeLineEdit->text().toInt();
                emit SetTime(index, t);
            });
}

void ResourcePage::TranslateUI()
{
    sunLabel->setText(tr("Sun"));
    sunButton->setText(tr("Set"));

    sunLimitLabel->setText(tr("Sun Limit"));
    sunLimitButton->setText(tr("Set"));

    moneyLabel->setText(tr("Money") + " x10");
    moneyButton->setText(tr("Set"));

    moneyLimitLabel->setText(tr("Money Limit") + " x10");
    moneyLimitButton->setText(tr("Set"));

    manyFallingSunCheckBox->setText(tr("Many Falling Sun"));
    noFallingSunCheckBox->setText(tr("No Falling Sun"));
    autoCollectCheckBox->setText(tr("Auto Collect"));
    zombieNoFallingCheckBox->setText(tr("Zombie No Falling"));

    manyFallingSunCheckBox->setStatusTip(tr("This feature is available when \"Auto Collect\" is turned on."));

    valueLabel->setText(tr("Value") + " x10");
    SET_COMBO_TEXT(valueCombo, List::Get().coinList, 6);
    valueButton->setText(tr("Set"));

    damageLabel->setText(tr("Damage"));
    SET_COMBO_TEXT(damageCombo, List::Get().damageList, 18);
    damageButton->setText(tr("Set"));

    hpLabel->setText(tr("HP"));
    SET_COMBO_TEXT(hpCombo, List::Get().hpList, 31);
    hpButton->setText(tr("Set"));

    timeLabel->setText(tr("Time") + " " + "(" + "cs" + ")");
    SET_COMBO_TEXT(timeCombo, List::Get().timeList, 13);
    timeButton->setText(tr("Set"));
}

void ResourcePage::ShowValue(int value)
{
    valueLineEdit->setText(QString::number(value));
}

void ResourcePage::ShowDamage(int damage)
{
    damageLineEdit->setText(QString::number(damage));
}

void ResourcePage::ShowHP(int hp)
{
    hpLineEdit->setText(QString::number(hp));
}

void ResourcePage::ShowTime(int t)
{
    timeLineEdit->setText(QString::number(t));
}

void ResourcePage::UpdateGameData()
{
    emit GetValue(valueCombo->currentIndex());
    emit GetDamage(damageCombo->currentIndex());
    emit GetHP(hpCombo->currentIndex());
    emit GetTime(timeCombo->currentIndex());
}

void ResourcePage::SetQuickLineupMode(bool on)
{
    if (on)
    {
        autoCollectCheckBox->setEnabled(false);
        emit AutoCollect(true);
    }
    else
    {
        autoCollectCheckBox->setEnabled(true);
        emit AutoCollect(autoCollectCheckBox->isChecked());
    }
}

void ResourcePage::KeepSelectedFeatures()
{
    if (manyFallingSunCheckBox->isChecked())
        emit SetFallingSun(Sun::Many);

    if (noFallingSunCheckBox->isChecked())
        emit SetFallingSun(Sun::None);

    if (autoCollectCheckBox->isChecked())
        emit AutoCollect(true);

    if (zombieNoFallingCheckBox->isChecked())
        emit ZombieNoFalling(true);
}

// Plants

PlantsPage::PlantsPage(QWidget *parent)
    : QWidget(parent)
{
    cobsNoCdCheckBox = new QCheckBox(this);
    magnetsNoCdCheckBox = new QCheckBox(this);
    potatoMineNoCdCheckBox = new QCheckBox(this);
    chomperNoCdCheckBox = new QCheckBox(this);

    plantInvincibleCheckBox = new QCheckBox(this);
    plantWeakCheckBox = new QCheckBox(this);
    lockKernelCheckBox = new QCheckBox(this);
    lockButterCheckBox = new QCheckBox(this);

    noCraterCheckBox = new QCheckBox(this);
    mushroomsAwakeCheckBox = new QCheckBox(this);
    strongBloverCheckBox = new QCheckBox(this);
    strongPeasCheckBox = new QCheckBox(this);

    explodeImmediatelyCheckBox = new QCheckBox(this);
    explodeNeverCheckBox = new QCheckBox(this);
    beghouledFreeMoveCheckBox = new QCheckBox(this);
    attackSuperpositionCheckBox = new QCheckBox(this);

    plantTorchwoodCheckBox = new QCheckBox(this);
    plantGarlicCheckBox = new QCheckBox(this);
    plantUmbrellaCheckBox = new QCheckBox(this);
    plantPaperCheckBox = new QCheckBox(this);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(cobsNoCdCheckBox, 0, 0, 1, 1);
    mainLayout->addWidget(magnetsNoCdCheckBox, 0, 1, 1, 1);
    mainLayout->addWidget(potatoMineNoCdCheckBox, 0, 2, 1, 1);
    mainLayout->addWidget(chomperNoCdCheckBox, 0, 3, 1, 1);
    mainLayout->addWidget(plantInvincibleCheckBox, 1, 0, 1, 1);
    mainLayout->addWidget(plantWeakCheckBox, 1, 1, 1, 1);
    mainLayout->addWidget(lockKernelCheckBox, 1, 2, 1, 1);
    mainLayout->addWidget(lockButterCheckBox, 1, 3, 1, 1);
    mainLayout->addWidget(noCraterCheckBox, 2, 0, 1, 1);
    mainLayout->addWidget(mushroomsAwakeCheckBox, 2, 1, 1, 1);
    mainLayout->addWidget(strongBloverCheckBox, 2, 2, 1, 1);
    mainLayout->addWidget(strongPeasCheckBox, 2, 3, 1, 1);
    mainLayout->addWidget(explodeImmediatelyCheckBox, 3, 0, 1, 1);
    mainLayout->addWidget(explodeNeverCheckBox, 3, 1, 1, 1);
    mainLayout->addWidget(beghouledFreeMoveCheckBox, 3, 2, 1, 1);
    mainLayout->addWidget(attackSuperpositionCheckBox, 3, 3, 1, 1);
    mainLayout->addWidget(plantTorchwoodCheckBox, 4, 0, 1, 1);
    mainLayout->addWidget(plantGarlicCheckBox, 4, 1, 1, 1);
    mainLayout->addWidget(plantUmbrellaCheckBox, 4, 2, 1, 1);
    mainLayout->addWidget(plantPaperCheckBox, 4, 3, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(plantInvincibleCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    plantWeakCheckBox->setChecked(false);
            });

    connect(plantWeakCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    plantInvincibleCheckBox->setChecked(false);
            });

    connect(lockKernelCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    lockButterCheckBox->setChecked(false);
            });

    connect(lockButterCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    lockKernelCheckBox->setChecked(false);
            });

    connect(explodeImmediatelyCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    explodeNeverCheckBox->setChecked(false);
            });

    connect(explodeNeverCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    explodeImmediatelyCheckBox->setChecked(false);
            });

    connect(cobsNoCdCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::CobCannonNoCD);

    connect(magnetsNoCdCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::MagnetsNoCD);

    connect(potatoMineNoCdCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::PotatoMineNoCD);

    connect(chomperNoCdCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::ChomperNoCD);

    connect(plantInvincibleCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetPlantStrength(Strength::Invincible);
                else
                    emit SetPlantStrength(Strength::Normal);
            });

    connect(plantWeakCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetPlantStrength(Strength::Weak);
                else
                    emit SetPlantStrength(Strength::Normal);
            });

    connect(lockKernelCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit LockPult(Bullet::Kernel);
                else
                    emit LockPult(Bullet::Normal);
            });

    connect(lockButterCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit LockPult(Bullet::Butter);
                else
                    emit LockPult(Bullet::Normal);
            });

    connect(noCraterCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::NoCrater);

    connect(mushroomsAwakeCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::MushroomsAwake);

    connect(strongBloverCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::StrongBlover);

    connect(strongPeasCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::StrongPeas);

    connect(explodeImmediatelyCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetPlantExplode(Explode::Immediately);
                else
                    emit SetPlantExplode(Explode::Normal);
            });

    connect(explodeNeverCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetPlantExplode(Explode::Never);
                else
                    emit SetPlantExplode(Explode::Normal);
            });

    connect(beghouledFreeMoveCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::BeghouledFreeMove);

    connect(attackSuperpositionCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::AttackSuperposition);

    connect(plantTorchwoodCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::PlantTorchwood);

    connect(plantGarlicCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::PlantGarlic);

    connect(plantUmbrellaCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::PlantUmbrella);

    connect(plantPaperCheckBox, &QCheckBox::clicked,
            this, &PlantsPage::PlantPaper);
}

void PlantsPage::TranslateUI()
{
    cobsNoCdCheckBox->setText(tr("Cob Cannon NoCD"));
    magnetsNoCdCheckBox->setText(tr("Magnets NoCD"));
    potatoMineNoCdCheckBox->setText(tr("Potato Mine NoCD"));
    chomperNoCdCheckBox->setText(tr("Chomper NoCD"));

    plantInvincibleCheckBox->setText(tr("Plant Invincible"));
    plantWeakCheckBox->setText(tr("Plant Weak"));
    lockKernelCheckBox->setText(tr("Lock Kernel"));
    lockButterCheckBox->setText(tr("Lock Butter"));

    noCraterCheckBox->setText(tr("No Crater"));
    mushroomsAwakeCheckBox->setText(tr("Mushrooms Awake"));
    strongBloverCheckBox->setText(tr("Strong Blover"));
    strongPeasCheckBox->setText(tr("Strong Peas"));

    explodeImmediatelyCheckBox->setText(tr("Explode Immediately"));
    explodeNeverCheckBox->setText(tr("Explode Never"));
    beghouledFreeMoveCheckBox->setText(tr("Beghouled Free Move"));
    attackSuperpositionCheckBox->setText(tr("Attack Superposition"));

    plantTorchwoodCheckBox->setText(tr("Plant Torchwood"));
    plantGarlicCheckBox->setText(tr("Plant Garlic"));
    plantUmbrellaCheckBox->setText(tr("Plant Umbrella"));
    plantPaperCheckBox->setText(tr("Plant Paper"));
}

void PlantsPage::SetQuickLineupMode(bool on)
{
    if (on)
    {
        cobsNoCdCheckBox->setEnabled(false);
        plantInvincibleCheckBox->setEnabled(false);
        plantWeakCheckBox->setEnabled(false);
        emit CobCannonNoCD(true);
        emit SetPlantStrength(Strength::Invincible);
    }
    else
    {
        cobsNoCdCheckBox->setEnabled(true);
        plantInvincibleCheckBox->setEnabled(true);
        plantWeakCheckBox->setEnabled(true);
        emit CobCannonNoCD(cobsNoCdCheckBox->isChecked());
        if (plantInvincibleCheckBox->isChecked())
            emit SetPlantStrength(Strength::Invincible);
        else if (plantWeakCheckBox->isChecked())
            emit SetPlantStrength(Strength::Weak);
        else
            emit SetPlantStrength(Strength::Normal);
    }
}

void PlantsPage::KeepSelectedFeatures()
{
    if (cobsNoCdCheckBox->isChecked())
        emit CobCannonNoCD(true);

    if (magnetsNoCdCheckBox->isChecked())
        emit MagnetsNoCD(true);

    if (potatoMineNoCdCheckBox->isChecked())
        emit PotatoMineNoCD(true);

    if (chomperNoCdCheckBox->isChecked())
        emit ChomperNoCD(true);

    if (plantInvincibleCheckBox->isChecked())
        emit SetPlantStrength(Strength::Invincible);

    if (plantWeakCheckBox->isChecked())
        emit SetPlantStrength(Strength::Weak);

    if (lockKernelCheckBox->isChecked())
        emit LockPult(Bullet::Kernel);

    if (lockButterCheckBox->isChecked())
        emit LockPult(Bullet::Butter);

    if (noCraterCheckBox->isChecked())
        emit NoCrater(true);

    if (mushroomsAwakeCheckBox->isChecked())
        emit MushroomsAwake(true);

    if (strongBloverCheckBox->isChecked())
        emit StrongBlover(true);

    if (strongPeasCheckBox->isChecked())
        emit StrongPeas(true);

    if (explodeImmediatelyCheckBox->isChecked())
        emit SetPlantExplode(Explode::Immediately);

    if (explodeNeverCheckBox->isChecked())
        emit SetPlantExplode(Explode::Never);

    if (beghouledFreeMoveCheckBox->isChecked())
        emit BeghouledFreeMove(true);

    if (attackSuperpositionCheckBox->isChecked())
        emit AttackSuperposition(true);

    if (plantTorchwoodCheckBox->isChecked())
        emit PlantTorchwood(true);

    if (plantGarlicCheckBox->isChecked())
        emit PlantGarlic(true);

    if (plantUmbrellaCheckBox->isChecked())
        emit PlantUmbrella(true);

    if (plantPaperCheckBox->isChecked())
        emit PlantPaper(true);
}

// Zombies

ZombiesPage::ZombiesPage(QWidget *parent)
    : QWidget(parent)
{
    zombieExplodeImmediatelyCheckBox = new QCheckBox(this);
    zombieExplodeNeverCheckBox = new QCheckBox(this);

    zombieInvisibleCheckBox = new QCheckBox(this);
    zombieShowCheckBox = new QCheckBox(this);

    zombieInvincibleCheckBox = new QCheckBox(this);
    zombieWeakCheckBox = new QCheckBox(this);

    stopSpawningCheckBox = new QCheckBox(this);
    zombiesNoMoveCheckBox = new QCheckBox(this);

    noIceSlowDownCheckBox = new QCheckBox(this);
    noButterImmobilizeCheckBox = new QCheckBox(this);
    no3ZombiesGroupCheckBox = new QCheckBox(this);
    noIceTrailCheckBox = new QCheckBox(this);

    noThrowImpCheckBox = new QCheckBox(this);
    gargantuarEatableCheckBox = new QCheckBox(this);
    zombossNoMoveCheckBox = new QCheckBox(this);
    balloonBurstCheckBox = new QCheckBox(this);

    gatherZombiesCheckBox = new QCheckBox(this);
    gatherZombiesSlider = new QSlider(this);
    gatherZombiesSlider->setOrientation(Qt::Horizontal);
    gatherZombiesSlider->setMinimum(0);
    gatherZombiesSlider->setMaximum(800);
    gatherZombiesSlider->setSingleStep(1);
    gatherZombiesSlider->setPageStep(100);
    gatherZombiesSlider->setValue(600);

    spawningNextWaveButton = new QPushButton(this);
    allZombiesLabel = new QLabel(this);
    allZombiesLabel->setAlignment(Qt::AlignCenter);
    allZombiesCombo = new QComboBox(this);
    allZombiesButton = new QPushButton(this);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(zombieExplodeImmediatelyCheckBox, 0, 0, 1, 1);
    mainLayout->addWidget(zombieExplodeNeverCheckBox, 0, 1, 1, 1);
    mainLayout->addWidget(zombieInvisibleCheckBox, 1, 0, 1, 1);
    mainLayout->addWidget(zombieShowCheckBox, 1, 1, 1, 1);
    mainLayout->addWidget(zombieInvincibleCheckBox, 2, 0, 1, 1);
    mainLayout->addWidget(zombieWeakCheckBox, 2, 1, 1, 1);
    mainLayout->addWidget(stopSpawningCheckBox, 3, 0, 1, 1);
    mainLayout->addWidget(zombiesNoMoveCheckBox, 3, 1, 1, 1);
    mainLayout->addWidget(noIceSlowDownCheckBox, 0, 2, 1, 1);
    mainLayout->addWidget(noButterImmobilizeCheckBox, 0, 3, 1, 1);
    mainLayout->addWidget(no3ZombiesGroupCheckBox, 1, 2, 1, 1);
    mainLayout->addWidget(noIceTrailCheckBox, 1, 3, 1, 1);
    mainLayout->addWidget(noThrowImpCheckBox, 2, 2, 1, 1);
    mainLayout->addWidget(gargantuarEatableCheckBox, 2, 3, 1, 1);
    mainLayout->addWidget(zombossNoMoveCheckBox, 3, 2, 1, 1);
    mainLayout->addWidget(balloonBurstCheckBox, 3, 3, 1, 1);
    mainLayout->addWidget(gatherZombiesCheckBox, 4, 0, 1, 1);
    mainLayout->addWidget(gatherZombiesSlider, 4, 1, 1, 3);
    mainLayout->addWidget(spawningNextWaveButton, 5, 0, 1, 1);
    mainLayout->addWidget(allZombiesLabel, 5, 1, 1, 1);
    mainLayout->addWidget(allZombiesCombo, 5, 2, 1, 1);
    mainLayout->addWidget(allZombiesButton, 5, 3, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(zombieExplodeImmediatelyCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    zombieExplodeNeverCheckBox->setChecked(false);
            });

    connect(zombieExplodeNeverCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    zombieExplodeImmediatelyCheckBox->setChecked(false);
            });

    connect(zombieInvisibleCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    zombieShowCheckBox->setChecked(false);
            });

    connect(zombieShowCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    zombieInvisibleCheckBox->setChecked(false);
            });

    connect(zombieInvincibleCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    zombieWeakCheckBox->setChecked(false);
            });

    connect(zombieWeakCheckBox, &QCheckBox::stateChanged,
            [=](int state) {
                if (state == Qt::Checked)
                    zombieInvincibleCheckBox->setChecked(false);
            });

    connect(zombieExplodeImmediatelyCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetZombieExplode(Explode::Immediately);
                else
                    emit SetZombieExplode(Explode::Normal);
            });

    connect(zombieExplodeNeverCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetZombieExplode(Explode::Never);
                else
                    emit SetZombieExplode(Explode::Normal);
            });

    connect(zombieInvisibleCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetZombieVisibility(Visibility::Invisible);
                else
                    emit SetZombieVisibility(Visibility::Normal);
            });

    connect(zombieShowCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetZombieVisibility(Visibility::Visible);
                else
                    emit SetZombieVisibility(Visibility::Normal);
            });

    connect(zombieInvincibleCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetZombieStrength(Strength::Invincible);
                else
                    emit SetZombieStrength(Strength::Normal);
            });

    connect(zombieWeakCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                if (checked)
                    emit SetZombieStrength(Strength::Weak);
                else
                    emit SetZombieStrength(Strength::Normal);
            });

    connect(stopSpawningCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::StopSpawning);

    connect(zombiesNoMoveCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::ZombiesNoMove);

    connect(noIceSlowDownCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::NoIceSlowDown);

    connect(noButterImmobilizeCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::NoButterImmobilize);

    connect(no3ZombiesGroupCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::No3zGroup);

    connect(noIceTrailCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::NoIceTrail);

    connect(noThrowImpCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::NoThrowImp);

    connect(gargantuarEatableCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::GargantuarEatable);

    connect(zombossNoMoveCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::ZombossNoMove);

    connect(balloonBurstCheckBox, &QCheckBox::clicked,
            this, &ZombiesPage::BalloonBurst);

    connect(gatherZombiesCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                float pos = static_cast<float>(gatherZombiesSlider->value());
                emit GatherZombies(checked, pos);
            });

    connect(gatherZombiesSlider, &QSlider::valueChanged,
            this, [=](int value) {
                if (gatherZombiesCheckBox->isChecked())
                    emit GatherZombies(true, static_cast<float>(value));
            });

    connect(spawningNextWaveButton, &QPushButton::clicked,
            this, &ZombiesPage::SpawningNextWave);

    connect(allZombiesButton, &QPushButton::clicked,
            this, [=]() {
                int zombie_status = allZombiesCombo->currentIndex();
                emit AllZombiesXXX(zombie_status);
            });
}

void ZombiesPage::TranslateUI()
{
    zombieExplodeImmediatelyCheckBox->setText(tr("Immediately Explode"));
    zombieExplodeNeverCheckBox->setText(tr("Never Explode"));

    zombieInvisibleCheckBox->setText(tr("Zombie Invisible"));
    zombieShowCheckBox->setText(tr("Zombie Show"));

    zombieInvincibleCheckBox->setText(tr("Zombie Invincible"));
    zombieWeakCheckBox->setText(tr("Zombie Weak"));

    stopSpawningCheckBox->setText(tr("Stop Spawning"));
    zombiesNoMoveCheckBox->setText(tr("Zombies No Move"));

    noIceSlowDownCheckBox->setText(tr("No Ice Slow Down"));
    noButterImmobilizeCheckBox->setText(tr("No Butter Immobilize"));
    no3ZombiesGroupCheckBox->setText(tr("No 3 Zombies Group"));
    noIceTrailCheckBox->setText(tr("No Ice Trail"));

    noThrowImpCheckBox->setText(tr("No Throw Imp"));
    gargantuarEatableCheckBox->setText(tr("Gargantuar Eatable"));
    zombossNoMoveCheckBox->setText(tr("Zomboss No Move"));
    balloonBurstCheckBox->setText(tr("Balloon Burst"));

    gatherZombiesCheckBox->setText(tr("Gather Zombies"));

    spawningNextWaveButton->setText(tr("Next Wave"));

    allZombiesLabel->setText(tr("All Zombies"));
    SET_COMBO_TEXT(allZombiesCombo, List::Get().zombieStatusList, 10);
    allZombiesButton->setText(tr("Set"));
}

void ZombiesPage::SetQuickLineupMode(bool on)
{
    if (on)
    {
        stopSpawningCheckBox->setEnabled(false);
        emit StopSpawning(true);
    }
    else
    {
        stopSpawningCheckBox->setEnabled(true);
        emit StopSpawning(stopSpawningCheckBox->isChecked());
    }
}

void ZombiesPage::KeepSelectedFeatures()
{
    if (zombieExplodeImmediatelyCheckBox->isChecked())
        emit SetZombieExplode(Explode::Immediately);

    if (zombieExplodeNeverCheckBox->isChecked())
        emit SetZombieExplode(Explode::Never);

    if (zombieInvisibleCheckBox->isChecked())
        emit SetZombieVisibility(Visibility::Invisible);

    if (zombieShowCheckBox->isChecked())
        emit SetZombieVisibility(Visibility::Visible);

    if (zombieInvincibleCheckBox->isChecked())
        emit SetZombieStrength(Strength::Invincible);

    if (zombieWeakCheckBox->isChecked())
        emit SetZombieStrength(Strength::Weak);

    if (stopSpawningCheckBox->isChecked())
        emit StopSpawning(true);

    if (zombiesNoMoveCheckBox->isChecked())
        emit ZombiesNoMove(true);

    if (noIceSlowDownCheckBox->isChecked())
        emit NoIceSlowDown(true);

    if (noButterImmobilizeCheckBox->isChecked())
        emit NoButterImmobilize(true);

    if (no3ZombiesGroupCheckBox->isChecked())
        emit No3zGroup(true);

    if (noIceTrailCheckBox->isChecked())
        emit NoIceTrail(true);

    if (noThrowImpCheckBox->isChecked())
        emit NoThrowImp(true);

    if (gargantuarEatableCheckBox->isChecked())
        emit GargantuarEatable(true);

    if (zombossNoMoveCheckBox->isChecked())
        emit ZombossNoMove(true);

    if (balloonBurstCheckBox->isChecked())
        emit BalloonBurst(true);

    if (gatherZombiesCheckBox->isChecked())
    {
        float pos = static_cast<float>(gatherZombiesSlider->value());
        emit GatherZombies(true, pos);
    }
}

// Spawn

SpawnBriefPage::SpawnBriefPage(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<std::array<bool, 33>>("std::array<bool, 33>");
    qRegisterMetaType<std::array<bool, 20>>("std::array<bool, 20>");

    limit_count = true;

    unsigned int tmp[20] = {2, 3, 4, 5, 6,
                            7, 8, 11, 12, 14,
                            15, 16, 17, 18, 19,
                            20, 21, 22, 23, 32};
    memcpy(zombieTypes, tmp, sizeof(tmp));

    spawnBriefWidget = new QWidget(this);

    for (size_t i = 0; i < 20; i++)
        spawnCheckBox[i] = new QCheckBox(spawnBriefWidget);

    spawnBriefLayout = new QGridLayout(spawnBriefWidget);
    for (size_t r = 0; r < 4; r++)
        for (size_t c = 0; c < 5; c++)
            spawnBriefLayout->addWidget(spawnCheckBox[r * 5 + c], r, c, 1, 1);

    for (int i = 0; i < spawnBriefLayout->rowCount(); i++)
        spawnBriefLayout->setRowStretch(i, 1);
    for (int i = 0; i < spawnBriefLayout->columnCount(); i++)
        spawnBriefLayout->setColumnStretch(i, 1);

    naturalSpawnButton = new QPushButton(this);
    extremeSpawnButton = new QPushButton(this);

    detailedModeButton = new QPushButton(this);
    showSpawnCountButton = new QPushButton(this);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(spawnBriefWidget, 0, 0, 10, 4);
    mainLayout->addWidget(naturalSpawnButton, 10, 2, 1, 1);
    mainLayout->addWidget(extremeSpawnButton, 10, 3, 1, 1);
    mainLayout->addWidget(detailedModeButton, 10, 0, 1, 1);
    mainLayout->addWidget(showSpawnCountButton, 10, 1, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    // zombieTypes[i] == 2 / 5, i == 0 / 3
    connect(spawnCheckBox[0], &QCheckBox::stateChanged,
            this, [=](int state) {
                if (limit_count && state == Qt::Checked)
                    spawnCheckBox[3]->setChecked(false);
            });
    connect(spawnCheckBox[3], &QCheckBox::stateChanged,
            this, [=](int state) {
                if (limit_count && state == Qt::Checked)
                    spawnCheckBox[0]->setChecked(false);
            });

    for (size_t i = 0; i < 20; i++)
        if ((zombieTypes[i] != 19) && (zombieTypes[i] != 20))
            connect(spawnCheckBox[i], &QCheckBox::stateChanged,
                    this, &SpawnBriefPage::CountCheck);

    connect(detailedModeButton, &QPushButton::clicked,
            this, &SpawnBriefPage::SwitchToDetailedPage);

    connect(detailedModeButton, &QPushButton::clicked,
            this, &SpawnBriefPage::GetRandomSeed);

    connect(showSpawnCountButton, &QPushButton::clicked,
            this, &SpawnBriefPage::ShowSpawnCountPage);

    connect(naturalSpawnButton, &QPushButton::clicked,
            this, [=]() {
                std::array<bool, 33> zombies = GetZombies();
                zombies[0] = true;
                emit InternalSpawn(zombies, false);
            });

    connect(extremeSpawnButton, &QPushButton::clicked,
            this, [=]() {
                std::array<bool, 33> zombies = GetZombies();
                zombies[0] = true;
                zombies[1] = true;
                std::array<bool, 20> giga_waves; // useless
                giga_waves.fill(true);
                emit CustomizeSpawn(zombies, false, true, true, true, false, giga_waves, 1000);
            });
}

void SpawnBriefPage::TranslateUI()
{
    for (size_t i = 0; i < 20; i++)
        spawnCheckBox[i]->setText(List::Get().zombieList[zombieTypes[i]]);

    naturalSpawnButton->setText(tr("Natural (Built-in Generate)"));
    extremeSpawnButton->setText(tr("Extreme (Filling Evenly)"));

    detailedModeButton->setText(tr("Switch Detailed Mode"));
    showSpawnCountButton->setText(tr("Spawning Counting"));
}

void SpawnBriefPage::SwitchLayout(bool on)
{
    if (on)
    {
        unsigned int types[20] = {2, 5, 4, 6, 16,
                                  21, 3, 8, 11, 18,
                                  12, 15, 7, 17, 14,
                                  22, 23, 32, 20, 19};
        for (size_t r = 0; r < 4; r++)
            for (size_t c = 0; c < 5; c++)
                for (size_t i = 0; i < 4; i++)
                    for (size_t j = 0; j < 5; j++)
                        if (types[r * 5 + c] == zombieTypes[i * 5 + j])
                            spawnBriefLayout->addWidget(spawnCheckBox[i * 5 + j], r, c, 1, 1);
    }
    else
    {
        for (size_t r = 0; r < 4; r++)
            for (size_t c = 0; c < 5; c++)
                spawnBriefLayout->addWidget(spawnCheckBox[r * 5 + c], r, c, 1, 1);
    }
}

void SpawnBriefPage::LimitSpawnCount(bool on)
{
    limit_count = on;
    CountCheck();
}

void SpawnBriefPage::CountCheck()
{
    int zombieTypeCount = 1;
    for (size_t i = 0; i < 20; i++)
        if ((zombieTypes[i] != 19) && (zombieTypes[i] != 20))
            zombieTypeCount += spawnCheckBox[i]->isChecked() ? 1 : 0;

    for (size_t i = 0; i < 20; i++)
    {
        if ((zombieTypes[i] != 19) && (zombieTypes[i] != 20))
        {
            if (limit_count && zombieTypeCount >= 11)
            {
                if (!spawnCheckBox[i]->isChecked())
                    spawnCheckBox[i]->setEnabled(false);
            }
            else
            {
                if (!spawnCheckBox[i]->isEnabled())
                    spawnCheckBox[i]->setEnabled(true);
            }
        }
    }
}

std::array<bool, 33> SpawnBriefPage::GetZombies()
{
    std::array<bool, 33> zombies = {false};
    for (size_t i = 0; i < 20; i++)
        zombies[zombieTypes[i]] = spawnCheckBox[i]->isChecked();
    return zombies;
}

void SpawnBriefPage::SetZombies(std::array<bool, 33> zombies)
{
    for (size_t i = 0; i < 20; i++)
        spawnCheckBox[i]->setChecked(zombies[zombieTypes[i]]);
}

SpawnDetailedPage::SpawnDetailedPage(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<std::array<bool, 33>>("std::array<bool, 33>");
    qRegisterMetaType<std::array<bool, 20>>("std::array<bool, 20>");

    QRegExp regExpHex("[a-fA-F0-9]{8}");
    randomSeedLineEdit = new QLineEdit(this);
    randomSeedLineEdit->setValidator(new QRegExpValidator(regExpHex, this));
    randomSeedLineEdit->setAlignment(Qt::AlignCenter);
    randomSeedButton = new QPushButton(this);

    spawnZombieCombo = new QComboBox(this);
    spawnAddButton = new QPushButton(this);
    spawnDeleteButton = new QPushButton(this);
    spawnClearButton = new QPushButton(this);

    spawnListWidget = new QListWidget(this);

    naturalSpawnRadioButton = new QRadioButton(this);
    extremeSpawnRadioButton = new QRadioButton(this);
    simulateSpawnRadioButton = new QRadioButton(this);

    spawnLimitWidget = new QWidget(this);

    limitFlagCheckBox = new QCheckBox(spawnLimitWidget);
    limitYetiCheckBox = new QCheckBox(spawnLimitWidget);
    limitBungeeCheckBox = new QCheckBox(spawnLimitWidget);
    limitGigaCheckBox = new QCheckBox(spawnLimitWidget);
    weightGigaLabel = new QLabel(spawnLimitWidget);
    weightGigaSpinBox = new QSpinBox(spawnLimitWidget);

    spawnLimitLayout = new QGridLayout(spawnLimitWidget);
    spawnLimitLayout->addWidget(limitFlagCheckBox, 0, 0, 1, 2);
    spawnLimitLayout->addWidget(limitYetiCheckBox, 0, 2, 1, 2);
    spawnLimitLayout->addWidget(limitBungeeCheckBox, 0, 4, 1, 2);
    spawnLimitLayout->addWidget(limitGigaCheckBox, 0, 6, 1, 2);
    spawnLimitLayout->addWidget(weightGigaLabel, 0, 0, 1, 3);
    spawnLimitLayout->addWidget(weightGigaSpinBox, 0, 3, 1, 2);
    spawnLimitLayout->setMargin(0);

    for (int i = 0; i < spawnLimitLayout->rowCount(); i++)
        spawnLimitLayout->setRowStretch(i, 1);
    for (int i = 0; i < spawnLimitLayout->columnCount(); i++)
        spawnLimitLayout->setColumnStretch(i, 1);

    gigaWavesWidget = new QWidget(this);

    for (size_t i = 0; i < 20; i++)
        waveCheckBox[i] = new QCheckBox(gigaWavesWidget);

    waveLine9 = new QFrame(gigaWavesWidget);
    waveLine9->setFrameShape(QFrame::VLine);
    waveLine9->setFrameShadow(QFrame::Sunken);
    waveLine19 = new QFrame(gigaWavesWidget);
    waveLine19->setFrameShape(QFrame::VLine);
    waveLine19->setFrameShadow(QFrame::Sunken);

    gigaWavesLayout = new QHBoxLayout(gigaWavesWidget);
    for (size_t i = 0; i < 9; i++)
        gigaWavesLayout->addWidget(waveCheckBox[i]);
    gigaWavesLayout->addWidget(waveLine9);
    for (size_t i = 9; i < 19; i++)
        gigaWavesLayout->addWidget(waveCheckBox[i]);
    gigaWavesLayout->addWidget(waveLine19);
    gigaWavesLayout->addWidget(waveCheckBox[19]);
    gigaWavesLayout->setMargin(0);
    gigaWavesLayout->setSpacing(4);

    spawnResetButton = new QPushButton(this);
    spawnSetButton = new QPushButton(this);
    briefModeButton = new QPushButton(this);

    spawnSpacer1 = new QSpacerItem(10, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);
    spawnSpacer3 = new QSpacerItem(10, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);
    spawnSpacer5 = new QSpacerItem(10, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);
    spawnSpacer7 = new QSpacerItem(10, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);
    spawnSpacer9 = new QSpacerItem(10, 100, QSizePolicy::Minimum, QSizePolicy::Expanding);

    // Set default states, Checked/Enabled/Visible.

    naturalSpawnRadioButton->setChecked(true);

    limitFlagCheckBox->setChecked(true);
    limitYetiCheckBox->setChecked(true);
    limitBungeeCheckBox->setChecked(true);

    weightGigaLabel->setVisible(false);
    weightGigaSpinBox->setVisible(false);

    spawnLimitWidget->setEnabled(false);
    gigaWavesWidget->setEnabled(false);

    randomSeedLineEdit->setText("00000000");

    weightGigaSpinBox->setRange(1000, 6000);
    weightGigaSpinBox->setSingleStep(100);
    weightGigaSpinBox->setValue(1000);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(randomSeedLineEdit, 0, 0, 1, 1);
    mainLayout->addWidget(randomSeedButton, 2, 0, 1, 1);
    mainLayout->addWidget(spawnZombieCombo, 0, 1, 1, 1);
    mainLayout->addWidget(spawnAddButton, 0, 2, 1, 1);
    mainLayout->addWidget(spawnDeleteButton, 2, 2, 1, 1);
    mainLayout->addWidget(spawnClearButton, 2, 1, 1, 1);
    mainLayout->addWidget(spawnListWidget, 0, 3, 11, 1);
    mainLayout->addWidget(naturalSpawnRadioButton, 4, 0, 1, 1);
    mainLayout->addWidget(extremeSpawnRadioButton, 4, 1, 1, 1);
    mainLayout->addWidget(simulateSpawnRadioButton, 4, 2, 1, 1);
    mainLayout->addWidget(spawnLimitWidget, 6, 0, 1, 3);
    mainLayout->addWidget(gigaWavesWidget, 8, 0, 1, 3);
    mainLayout->addWidget(spawnResetButton, 10, 1, 1, 1);
    mainLayout->addWidget(spawnSetButton, 10, 2, 1, 1);
    mainLayout->addWidget(briefModeButton, 10, 0, 1, 1);
    mainLayout->addItem(spawnSpacer1, 1, 0, 1, 1);
    mainLayout->addItem(spawnSpacer3, 3, 0, 1, 1);
    mainLayout->addItem(spawnSpacer5, 5, 0, 1, 1);
    mainLayout->addItem(spawnSpacer7, 7, 0, 1, 1);
    mainLayout->addItem(spawnSpacer9, 9, 0, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(naturalSpawnRadioButton, &QRadioButton::toggled,
            this, [=](bool checked) {
                if (checked)
                {
                    spawnLimitWidget->setEnabled(false);
                    gigaWavesWidget->setEnabled(false);
                }
            });

    connect(extremeSpawnRadioButton, &QRadioButton::toggled,
            this, [=](bool checked) {
                if (checked)
                {
                    spawnLimitWidget->setEnabled(true);
                    weightGigaLabel->setVisible(false);
                    weightGigaSpinBox->setVisible(false);
                    limitFlagCheckBox->setVisible(true);
                    limitYetiCheckBox->setVisible(true);
                    limitBungeeCheckBox->setVisible(true);
                    if (limitGigaCheckBox->isChecked())
                        gigaWavesWidget->setEnabled(true);
                }
            });

    connect(simulateSpawnRadioButton, &QRadioButton::toggled,
            this, [=](bool checked) {
                if (checked)
                {
                    spawnLimitWidget->setEnabled(true);
                    limitFlagCheckBox->setVisible(false);
                    limitYetiCheckBox->setVisible(false);
                    limitBungeeCheckBox->setVisible(false);
                    weightGigaLabel->setVisible(true);
                    weightGigaSpinBox->setVisible(true);
                    if (limitGigaCheckBox->isChecked())
                        gigaWavesWidget->setEnabled(true);
                }
            });

    connect(limitGigaCheckBox, &QCheckBox::stateChanged,
            this, [=](int state) {
                if ((state == Qt::Checked)            //
                    && !waveCheckBox[0]->isChecked()  //
                    && !waveCheckBox[1]->isChecked()  //
                    && !waveCheckBox[2]->isChecked()  //
                    && !waveCheckBox[3]->isChecked()  //
                    && !waveCheckBox[4]->isChecked()  //
                    && !waveCheckBox[5]->isChecked()  //
                    && !waveCheckBox[6]->isChecked()  //
                    && !waveCheckBox[7]->isChecked()  //
                    && !waveCheckBox[8]->isChecked()  //
                    && !waveCheckBox[9]->isChecked()  //
                    && !waveCheckBox[10]->isChecked() //
                    && !waveCheckBox[11]->isChecked() //
                    && !waveCheckBox[12]->isChecked() //
                    && !waveCheckBox[13]->isChecked() //
                    && !waveCheckBox[14]->isChecked() //
                    && !waveCheckBox[15]->isChecked() //
                    && !waveCheckBox[16]->isChecked() //
                    && !waveCheckBox[17]->isChecked() //
                    && !waveCheckBox[18]->isChecked() //
                    && !waveCheckBox[19]->isChecked())
                {
                    bool speedChangeWaves[20] = {true, true, true, true, true, true, true, true, true,                //
                                                 true, false, false, false, false, false, false, false, false, false, //
                                                 true};
                    for (size_t i = 0; i < 20; i++)
                        waveCheckBox[i]->setChecked(speedChangeWaves[i]);
                }

                if (state == Qt::Checked)
                    gigaWavesWidget->setEnabled(true);
                else if (state == Qt::Unchecked)
                    gigaWavesWidget->setEnabled(false);
            });

    connect(spawnAddButton, &QPushButton::clicked,
            this, [=]() {
                QString spawn_item = spawnZombieCombo->currentText();
                QList<QListWidgetItem *> item_list = spawnListWidget->findItems(spawn_item, Qt::MatchContains);
                if (item_list.count() == 0)
                    spawnListWidget->addItem(spawn_item);
            });

    connect(spawnDeleteButton, &QPushButton::clicked,
            this, [=]() {
                int row = spawnListWidget->currentRow();
                if (row != -1)
                {
                    QListWidgetItem *item_take = spawnListWidget->takeItem(row);
                    delete item_take;
                }
                spawnListWidget->setCurrentRow(-1);
            });

    connect(spawnClearButton, &QPushButton::clicked,
            this, [=]() {
                spawnListWidget->clear();
            });

    connect(briefModeButton, &QPushButton::clicked,
            this, &SpawnDetailedPage::SwitchToBriefPage);

    connect(randomSeedButton, &QPushButton::clicked,
            this, [=]() {
                bool ok;
                int random_seed = randomSeedLineEdit->text().toInt(&ok, 16);
                if (ok)
                {
                    emit SetRandomSeed(random_seed);
                    std::array<bool, 33> zombies = {false}; // useless
                    emit InternalSpawn(zombies, true);
                }
            });

    connect(spawnResetButton, &QPushButton::clicked,
            this, [=]() {
                std::array<bool, 33> zombies = {false}; // useless
                emit InternalSpawn(zombies, true);
            });

    connect(spawnSetButton, &QPushButton::clicked,
            this, [=]() {
                std::array<bool, 33> zombies = GetZombies();

                if (naturalSpawnRadioButton->isChecked())
                    emit InternalSpawn(zombies, false);
                else
                {
                    bool simulate = simulateSpawnRadioButton->isChecked();
                    bool limit_flag = limitFlagCheckBox->isChecked();
                    bool limit_yeti = limitYetiCheckBox->isChecked();
                    bool limit_bungee = limitBungeeCheckBox->isChecked();
                    bool limit_giga = limitGigaCheckBox->isChecked();
                    std::array<bool, 20> giga_waves = GetGigaWaves();
                    int giga_weight = weightGigaSpinBox->value();
                    if (simulate)
                    {
                        zombies[0] = true;
                        zombies[1] = true;
                        limit_flag = true;
                        limit_yeti = true;
                        limit_bungee = true;
                    }
                    emit CustomizeSpawn(zombies, simulate, limit_flag, limit_yeti, limit_bungee, limit_giga, giga_waves, giga_weight);
                }
            });
}

void SpawnDetailedPage::TranslateUI()
{
    randomSeedButton->setText(tr("Set Seed"));

    // SET_COMBO_TEXT(spawnZombieCombo, List::Get().zombieList, 33);

    if (spawnZombieCombo->count() == 0)
        for (size_t i = 0; i < 33; i++)
            spawnZombieCombo->addItem(QString("[") + QString::number(i) + "]" + " " + List::Get().zombieList[i]);
    else
        for (size_t i = 0; i < 33; i++)
            spawnZombieCombo->setItemText(i, QString("[") + QString::number(i) + "]" + " " + List::Get().zombieList[i]);

    spawnAddButton->setText(tr("Add >>"));
    spawnDeleteButton->setText(tr("<< Delete"));
    spawnClearButton->setText(tr("Clear List"));

    naturalSpawnRadioButton->setText(tr("Natural Spawn"));
    extremeSpawnRadioButton->setText(tr("Extreme Spawn"));
    simulateSpawnRadioButton->setText(tr("Simulate Natural Spawn"));

    naturalSpawnRadioButton->setStatusTip(tr("Calls built-in function of game to generates zombies list."));
    extremeSpawnRadioButton->setStatusTip(tr("Continuously and evenly populate the zombies list."));
    simulateSpawnRadioButton->setStatusTip(tr("Randomly fill the zombies list according to some ratio."));

    limitFlagCheckBox->setText(tr("Limit Flag"));
    limitYetiCheckBox->setText(tr("Limit Yeti"));
    limitBungeeCheckBox->setText(tr("Limit Bungee"));
    limitGigaCheckBox->setText(tr("Limit Giga"));

    weightGigaLabel->setText(tr("Weight of GigaGargantuar in non huge waves:"));

    limitFlagCheckBox->setStatusTip(tr("Flag Zombie will only appear in each flag wave (huge wave)."));
    limitYetiCheckBox->setStatusTip(tr("There will be only one Zombie Yeti."));
    limitBungeeCheckBox->setStatusTip(tr("Bungee Zombie will only appear in flag wave (huge wave)."));
    limitGigaCheckBox->setStatusTip(tr("GigaGargantuar will only appear in selected wave(s) (20 waves total)."));

    gigaWavesWidget->setStatusTip(tr("These check boxes shows or controls the waves of GigaGargantuar appear."));

    spawnResetButton->setText(tr("Reset"));
    spawnSetButton->setText(tr("Set"));

    briefModeButton->setText(tr("Switch Brief Mode"));
}

std::array<bool, 33> SpawnDetailedPage::GetZombies()
{
    std::array<bool, 33> zombies = {false};
    for (int i = 0; i < 33; i++)
        zombies[i] = spawnListWidget->findItems(List::Get().zombieList[i], Qt::MatchContains).count() > 0 ? true : false;
    return zombies;
}

void SpawnDetailedPage::SetZombies(std::array<bool, 33> zombies)
{
    spawnListWidget->clear();
    for (size_t i = 0; i < 33; i++)
    {
        if (zombies[i])
        {
            QString spawn_item = QString("[") + QString::number(i) + "]" + " " + List::Get().zombieList[i];
            spawnListWidget->addItem(spawn_item);
        }
    }
}

std::array<bool, 20> SpawnDetailedPage::GetGigaWaves()
{
    std::array<bool, 20> giga_waves = {false};
    for (size_t i = 0; i < 20; i++)
        giga_waves[i] = waveCheckBox[i]->isChecked();
    return giga_waves;
}

void SpawnDetailedPage::ShowGigaWaves(std::array<uint32_t, 1000> zombies_list)
{
    std::array<bool, 20> giga_waves = {false};
    for (size_t i = 0; i < 20; i++)
        for (size_t j = 0; j < 50; j++)
            if (zombies_list[i * 50 + j] == 32)
            {
                giga_waves[i] = true;
                break;
            }

    for (size_t i = 0; i < 20; i++)
        waveCheckBox[i]->setChecked(giga_waves[i]);
}

void SpawnDetailedPage::ShowRandomSeed(int random_seed)
{
    QString seed_text = QString("%1").arg(random_seed, 8, 16, QLatin1Char('0')).toUpper();
    randomSeedLineEdit->setText(seed_text);
}

SpawnPage::SpawnPage(QWidget *parent)
    : QStackedWidget(parent)
{
    briefPage = new SpawnBriefPage(this);
    detailedPage = new SpawnDetailedPage(this);

    addWidget(briefPage);
    addWidget(detailedPage);

    connect(briefPage, &SpawnBriefPage::SwitchToDetailedPage,
            this, [=]() {
                setCurrentWidget(detailedPage);
                if (true) // TODO
                {
                    auto src_zombies = briefPage->GetZombies();
                    auto dst_zombies = detailedPage->GetZombies();

                    int count = 0;
                    for (size_t i = 0; i < 33; i++)
                        if (dst_zombies[i])
                            count++;

                    if (count == 0)
                        detailedPage->SetZombies(src_zombies);
                }
            });

    connect(detailedPage, &SpawnDetailedPage::SwitchToBriefPage,
            this, [=]() {
                setCurrentWidget(briefPage);
                if (true) // TODO
                {
                    auto src_zombies = detailedPage->GetZombies();
                    auto dst_zombies = briefPage->GetZombies();

                    int count = 0;
                    for (size_t i = 0; i < 33; i++)
                        if (dst_zombies[i])
                            count++;

                    if (count == 0)
                        briefPage->SetZombies(src_zombies);
                }
            });

    connect(briefPage, &SpawnBriefPage::ShowSpawnCountPage,
            this, &SpawnPage::ShowSpawnCountPage);

    connect(briefPage, &SpawnBriefPage::InternalSpawn,
            this, &SpawnPage::InternalSpawn);

    connect(briefPage, &SpawnBriefPage::CustomizeSpawn,
            this, &SpawnPage::CustomizeSpawn);

    connect(detailedPage, &SpawnDetailedPage::InternalSpawn,
            this, &SpawnPage::InternalSpawn);

    connect(detailedPage, &SpawnDetailedPage::CustomizeSpawn,
            this, &SpawnPage::CustomizeSpawn);

    connect(briefPage, &SpawnBriefPage::GetRandomSeed,
            this, &SpawnPage::GetRandomSeed);

    connect(detailedPage, &SpawnDetailedPage::SetRandomSeed,
            this, &SpawnPage::SetRandomSeed);
}

void SpawnPage::TranslateUI()
{
    briefPage->TranslateUI();
    detailedPage->TranslateUI();
}

std::array<bool, 33> SpawnPage::GetBriefZombies()
{
    return briefPage->GetZombies();
}

std::array<bool, 33> SpawnPage::GetDetailedZombies()
{
    return detailedPage->GetZombies();
}

void SpawnPage::SetBriefZombies(std::array<bool, 33> zombies)
{
    briefPage->SetZombies(zombies);
}

void SpawnPage::SetDetailedZombies(std::array<bool, 33> zombies)
{
    detailedPage->SetZombies(zombies);
}

void SpawnPage::ShowRandomSeed(int random_seed)
{
    detailedPage->ShowRandomSeed(random_seed);
}

void SpawnPage::ShowGigaWaves(std::array<uint32_t, 1000> giga_waves)
{
    detailedPage->ShowGigaWaves(giga_waves);
}

void SpawnPage::SwitchLayout(bool on)
{
    briefPage->SwitchLayout(on);
}

void SpawnPage::LimitSpawnCount(bool on)
{
    briefPage->LimitSpawnCount(on);
}

// Slots

SlotsPage::SlotsPage(QWidget *parent)
    : QWidget(parent)
{
    slotsCountLabel = new QLabel(this);
    slotsCountSpinBox = new QSpinBox(this);
    slotsCountSpinBox->setRange(1, 10);
    slotsCountSpinBox->setSingleStep(1);
    slotsCountSpinBox->setValue(10);
    slotsCountButton = new QPushButton(this);
    hideSlotsCheckBox = new QCheckBox(this);
    showShovelCheckBox = new QCheckBox(this);
    lockShovelCheckBox = new QCheckBox(this);

    slotsSlotCombo = new QComboBox(this);
    slotsSeedCombo = new QComboBox(this);
    slotsSetButton = new QPushButton(this);
    imitaterCheckBox = new QCheckBox(this);
    hideSlotsSeedCheckBox = new QCheckBox(this);

    ignoreSunCheckBox = new QCheckBox(this);
    slotsNoCdCheckBox = new QCheckBox(this);
    purpleSeedUnlimitedCheckBox = new QCheckBox(this);
    plantingFreelyCheckBox = new QCheckBox(this);
    beltNoDelayCheckBox = new QCheckBox(this);
    hideMenuButtonCheckBox = new QCheckBox(this);

    seedLabel = new QLabel(this);
    seedLabel->setAlignment(Qt::AlignCenter);
    seedCombo = new QComboBox(this);

    seedSpeedLabel = new QLabel(this);
    seedSpeedLabel->setAlignment(Qt::AlignCenter);
    seedSpeedLineEdit = new QLineEdit(this);
    seedSpeedLineEdit->setText("");
    seedSpeedLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    seedSpeedButton = new QPushButton(this);

    seedCostLabel = new QLabel(this);
    seedCostLabel->setAlignment(Qt::AlignCenter);
    seedCostLineEdit = new QLineEdit(this);
    seedCostLineEdit->setText("");
    seedCostLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    seedCostButton = new QPushButton(this);

    seedRechargeLabel = new QLabel(this);
    seedRechargeLabel->setAlignment(Qt::AlignCenter);
    seedRechargeLineEdit = new QLineEdit(this);
    seedRechargeLineEdit->setText("");
    seedRechargeLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    seedRechargeButton = new QPushButton(this);

    // Set default status.
    showShovelCheckBox->setChecked(true);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(slotsCountLabel, 0, 0, 1, 1);
    mainLayout->addWidget(slotsCountSpinBox, 0, 1, 1, 1);
    mainLayout->addWidget(slotsCountButton, 0, 2, 1, 1);
    mainLayout->addWidget(hideSlotsCheckBox, 0, 3, 1, 1);
    mainLayout->addWidget(showShovelCheckBox, 0, 4, 1, 1);
    mainLayout->addWidget(lockShovelCheckBox, 0, 5, 1, 1);
    mainLayout->addWidget(slotsSlotCombo, 1, 0, 1, 1);
    mainLayout->addWidget(slotsSeedCombo, 1, 1, 1, 2);
    mainLayout->addWidget(slotsSetButton, 1, 3, 1, 1);
    mainLayout->addWidget(imitaterCheckBox, 1, 4, 1, 1);
    mainLayout->addWidget(hideSlotsSeedCheckBox, 1, 5, 1, 1);
    mainLayout->addWidget(ignoreSunCheckBox, 2, 0, 1, 1);
    mainLayout->addWidget(slotsNoCdCheckBox, 2, 1, 1, 1);
    mainLayout->addWidget(purpleSeedUnlimitedCheckBox, 2, 2, 1, 1);
    mainLayout->addWidget(plantingFreelyCheckBox, 2, 3, 1, 1);
    mainLayout->addWidget(beltNoDelayCheckBox, 2, 4, 1, 1);
    mainLayout->addWidget(hideMenuButtonCheckBox, 2, 5, 1, 1);
    mainLayout->addWidget(seedLabel, 3, 0, 1, 1);
    mainLayout->addWidget(seedCombo, 3, 1, 1, 2);
    mainLayout->addWidget(seedSpeedLabel, 3, 3, 1, 1);
    mainLayout->addWidget(seedSpeedLineEdit, 3, 4, 1, 1);
    mainLayout->addWidget(seedSpeedButton, 3, 5, 1, 1);
    mainLayout->addWidget(seedCostLabel, 4, 0, 1, 1);
    mainLayout->addWidget(seedCostLineEdit, 4, 1, 1, 1);
    mainLayout->addWidget(seedCostButton, 4, 2, 1, 1);
    mainLayout->addWidget(seedRechargeLabel, 4, 3, 1, 1);
    mainLayout->addWidget(seedRechargeLineEdit, 4, 4, 1, 1);
    mainLayout->addWidget(seedRechargeButton, 4, 5, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(slotsSlotCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                emit GetSeedType(index);
                emit GetSeedVisible(index);
            });

    connect(slotsSeedCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                if (index >= 53)
                    imitaterCheckBox->setEnabled(false); // Zombies have no imitater.
                else
                    imitaterCheckBox->setEnabled(true);
                if (index == 53 || index == 54 || index == 55 || index == 56 || index == 57 || index == 75)
                    slotsSetButton->setEnabled(false); // Will crash.
                else
                    slotsSetButton->setEnabled(true);
            });

    connect(slotsCountButton, &QPushButton::clicked,
            this, [=]() {
                int num = slotsCountSpinBox->text().toInt();
                emit SetSlotsCount(num);
            });

    connect(hideSlotsCheckBox, &QCheckBox::clicked,
            this, &SlotsPage::HideSlots);

    connect(showShovelCheckBox, &QPushButton::clicked,
            this, &SlotsPage::ShowShovel);

    connect(lockShovelCheckBox, &QCheckBox::clicked,
            this, &SlotsPage::LockShovel);

    connect(slotsSetButton, &QPushButton::clicked,
            this, [=]() {
                int slot = slotsSlotCombo->currentIndex();
                int type = slotsSeedCombo->currentIndex();
                bool imitater = imitaterCheckBox->isChecked();
                emit SetSeedType(slot, type, imitater);
            });

    connect(hideSlotsSeedCheckBox, &QCheckBox::clicked,
            this, [=](bool checked) {
                int slot = slotsSlotCombo->currentIndex();
                bool visible = !checked;
                emit SetSeedVisible(slot, visible);
            });

    connect(ignoreSunCheckBox, &QCheckBox::clicked,
            this, &SlotsPage::IgnoreSun);

    connect(slotsNoCdCheckBox, &QCheckBox::clicked,
            this, &SlotsPage::SlotsNoCoolDown);

    connect(purpleSeedUnlimitedCheckBox, &QCheckBox::clicked,
            this, &SlotsPage::PurpleSeedUnlimited);

    connect(plantingFreelyCheckBox, &QCheckBox::clicked,
            this, &SlotsPage::PlantingFreely);

    connect(beltNoDelayCheckBox, &QCheckBox::clicked,
            this, &SlotsPage::BeltNoDelay);

    connect(hideMenuButtonCheckBox, &QCheckBox::clicked,
            this, &SlotsPage::HideMenuButton);

    connect(seedCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            [=](int index) {
                emit GetSpeed(index);
                emit GetCost(index);
                emit GetRecharge(index);
            });

    connect(seedSpeedButton, &QPushButton::clicked,
            this, [=]() {
                int index = seedCombo->currentIndex();
                int speed = seedSpeedLineEdit->text().toInt();
                emit SetSpeed(index, speed);
            });

    connect(seedCostButton, &QPushButton::clicked,
            this, [=]() {
                int index = seedCombo->currentIndex();
                int cost = seedCostLineEdit->text().toInt();
                emit SetCost(index, cost);
            });

    connect(seedRechargeButton, &QPushButton::clicked,
            this, [=]() {
                int index = seedCombo->currentIndex();
                int recharge = seedRechargeLineEdit->text().toInt();
                emit SetRecharge(index, recharge);
            });
}

void SlotsPage::TranslateUI()
{
    slotsCountLabel->setText(tr("Count of Slots"));
    slotsCountButton->setText(tr("Set"));

    hideSlotsCheckBox->setText(tr("Hide Slots"));
    showShovelCheckBox->setText(tr("Show Shovel"));
    lockShovelCheckBox->setText(tr("Lock Shovel"));

    SET_COMBO_TEXT(slotsSlotCombo, List::Get().slotsIndexList, 10);
    // SET_COMBO_TEXT(slotsSeedCombo, List::Get().seedList, 76);

    if (slotsSeedCombo->count() == 0)
        for (size_t i = 0; i < 76; i++)
            slotsSeedCombo->addItem(QString("[") + QString::number(i) + "]" + " " + List::Get().seedList[i]);
    else
        for (size_t i = 0; i < 76; i++)
            slotsSeedCombo->setItemText(i, QString("[") + QString::number(i) + "]" + " " + List::Get().seedList[i]);

    slotsSetButton->setText(tr("Set"));
    imitaterCheckBox->setText(tr("Imitater"));
    hideSlotsSeedCheckBox->setText(tr("Hide"));

    ignoreSunCheckBox->setText(tr("Ignore Sun"));
    slotsNoCdCheckBox->setText(tr("Seed No Cool Down"));
    purpleSeedUnlimitedCheckBox->setText(tr("Purple Seed Unlimited"));
    plantingFreelyCheckBox->setText(tr("Planting Freely"));
    beltNoDelayCheckBox->setText(tr("Belt No Delay"));
    hideMenuButtonCheckBox->setText(tr("Hide Menu Button"));

    seedLabel->setText(tr("Seed"));
    // SET_COMBO_TEXT(seedCombo, List::Get().seedList, 48);

    if (seedCombo->count() == 0)
        for (size_t i = 0; i < 48; i++)
            seedCombo->addItem(QString("[") + QString::number(i) + "]" + " " + List::Get().seedList[i]);
    else
        for (size_t i = 0; i < 48; i++)
            seedCombo->setItemText(i, QString("[") + QString::number(i) + "]" + " " + List::Get().seedList[i]);

    seedSpeedLabel->setText(tr("Speed"));
    seedSpeedButton->setText(tr("Set"));

    seedCostLabel->setText(tr("Cost"));
    seedCostButton->setText(tr("Set"));

    seedRechargeLabel->setText(tr("Recharge"));
    seedRechargeButton->setText(tr("Set"));
}

void SlotsPage::ShowSeedType(int type)
{
    slotsSeedCombo->setCurrentIndex(type);
}

void SlotsPage::ShowSeedImitater(bool imitater)
{
    imitaterCheckBox->setChecked(imitater);
}

void SlotsPage::ShowSeedVisible(bool visible)
{
    hideSlotsSeedCheckBox->setChecked(!visible);
}

void SlotsPage::ShowSpeed(int speed)
{
    seedSpeedLineEdit->setText(QString::number(speed));
}

void SlotsPage::ShowCost(int cost)
{
    seedCostLineEdit->setText(QString::number(cost));
}

void SlotsPage::ShowRecharge(int recharge)
{
    seedRechargeLineEdit->setText(QString::number(recharge));
}

void SlotsPage::UpdateGameData()
{
    emit GetSeedType(slotsSlotCombo->currentIndex());
    emit GetSeedVisible(slotsSlotCombo->currentIndex());
    emit GetSpeed(seedCombo->currentIndex());
    emit GetCost(seedCombo->currentIndex());
    emit GetRecharge(seedCombo->currentIndex());
}

void SlotsPage::SetQuickLineupMode(bool on)
{
    if (on)
    {
        ignoreSunCheckBox->setEnabled(false);
        slotsNoCdCheckBox->setEnabled(false);
        purpleSeedUnlimitedCheckBox->setEnabled(false);
        emit IgnoreSun(true);
        emit SlotsNoCoolDown(true);
        emit PurpleSeedUnlimited(true);
    }
    else
    {
        ignoreSunCheckBox->setEnabled(true);
        slotsNoCdCheckBox->setEnabled(true);
        purpleSeedUnlimitedCheckBox->setEnabled(true);
        emit IgnoreSun(ignoreSunCheckBox->isChecked());
        emit SlotsNoCoolDown(slotsNoCdCheckBox->isChecked());
        emit PurpleSeedUnlimited(purpleSeedUnlimitedCheckBox->isChecked());
    }
}

void SlotsPage::KeepSelectedFeatures()
{
    if (hideSlotsCheckBox->isChecked())
        emit HideSlots(true);

    if (!showShovelCheckBox->isChecked())
        emit ShowShovel(false);

    if (lockShovelCheckBox->isChecked())
        emit LockShovel(true);

    if (ignoreSunCheckBox->isChecked())
        emit IgnoreSun(true);

    if (slotsNoCdCheckBox->isChecked())
        emit SlotsNoCoolDown(true);

    if (purpleSeedUnlimitedCheckBox->isChecked())
        emit PurpleSeedUnlimited(true);

    if (plantingFreelyCheckBox->isChecked())
        emit PlantingFreely(true);

    if (beltNoDelayCheckBox->isChecked())
        emit BeltNoDelay(true);

    if (hideMenuButtonCheckBox->isChecked())
        emit HideMenuButton(true);
}

// Scene

ScenePage::ScenePage(QWidget *parent)
    : QWidget(parent)
{
    sceneRowLabel = new QLabel(this);
    sceneColLabel = new QLabel(this);

    sceneRowSpinBox = new QSpinBox(this);
    sceneRowSpinBox->setRange(0, 9);
    sceneRowSpinBox->setSingleStep(1);
    sceneRowSpinBox->setValue(1);
    sceneColSpinBox = new QSpinBox(this);
    sceneColSpinBox->setRange(0, 99);
    sceneColSpinBox->setSingleStep(1);
    sceneColSpinBox->setValue(1);

    plantMenuCombo = new QComboBox(this);
    putPlantButton = new QPushButton(this);
    imitaterCheckBox = new QCheckBox(this);

    zombieMenuCombo = new QComboBox(this);
    putZombieButton = new QPushButton(this);

    putGraveButton = new QPushButton(this);
    putRakeButton = new QPushButton(this);

    coinTypeCombo = new QComboBox(this);
    putCoinButton = new QPushButton(this);

    putLadderButton = new QPushButton(this);
    autoLadderButton = new QPushButton(this);
    imitaterPumpkinCheckBox = new QCheckBox(this);

    blockTypeLabel = new QLabel(this);
    blockTypeCombo = new QComboBox(this);
    blockTypeButton = new QPushButton(this);

    rowTypeLabel = new QLabel(this);
    rowTypeCombo = new QComboBox(this);
    rowTypeButton = new QPushButton(this);

    sceneLabel = new QLabel(this);
    sceneCombo = new QComboBox(this);
    sceneButton = new QPushButton(this);

    startLawnMowersButton = new QPushButton(this);
    clearLawnMowersButton = new QPushButton(this);
    resetLawnMowersButton = new QPushButton(this);

    musicLabel = new QLabel(this);
    musicCombo = new QComboBox(this);
    musicButton = new QPushButton(this);

    itemCombo = new QComboBox(this);
    clearItemButton = new QPushButton(this);

    // Set default status.
    imitaterPumpkinCheckBox->setChecked(true);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(sceneRowLabel, 0, 0, 1, 2);
    mainLayout->addWidget(sceneColLabel, 1, 0, 1, 2);
    mainLayout->addWidget(sceneRowSpinBox, 0, 2, 1, 2);
    mainLayout->addWidget(sceneColSpinBox, 1, 2, 1, 2);
    mainLayout->addWidget(plantMenuCombo, 0, 4, 1, 4);
    mainLayout->addWidget(putPlantButton, 0, 8, 1, 2);
    mainLayout->addWidget(imitaterCheckBox, 0, 10, 1, 2);
    mainLayout->addWidget(zombieMenuCombo, 1, 4, 1, 4);
    mainLayout->addWidget(putZombieButton, 1, 8, 1, 2);
    mainLayout->addWidget(putGraveButton, 2, 0, 1, 2);
    mainLayout->addWidget(putRakeButton, 2, 2, 1, 2);
    mainLayout->addWidget(coinTypeCombo, 2, 4, 1, 2);
    mainLayout->addWidget(putCoinButton, 2, 6, 1, 2);
    mainLayout->addWidget(putLadderButton, 2, 8, 1, 2);
    mainLayout->addWidget(autoLadderButton, 2, 10, 1, 2);
    mainLayout->addWidget(imitaterPumpkinCheckBox, 1, 10, 1, 2);
    mainLayout->addWidget(blockTypeLabel, 3, 0, 1, 2);
    mainLayout->addWidget(blockTypeCombo, 3, 2, 1, 2);
    mainLayout->addWidget(blockTypeButton, 3, 4, 1, 2);
    mainLayout->addWidget(rowTypeLabel, 3, 6, 1, 2);
    mainLayout->addWidget(rowTypeCombo, 3, 8, 1, 2);
    mainLayout->addWidget(rowTypeButton, 3, 10, 1, 2);
    mainLayout->addWidget(sceneLabel, 4, 0, 1, 2);
    mainLayout->addWidget(sceneCombo, 4, 2, 1, 2);
    mainLayout->addWidget(sceneButton, 4, 4, 1, 2);
    mainLayout->addWidget(startLawnMowersButton, 4, 6, 1, 2);
    mainLayout->addWidget(clearLawnMowersButton, 4, 8, 1, 2);
    mainLayout->addWidget(resetLawnMowersButton, 4, 10, 1, 2);
    mainLayout->addWidget(musicLabel, 5, 0, 1, 2);
    mainLayout->addWidget(musicCombo, 5, 2, 1, 3);
    mainLayout->addWidget(musicButton, 5, 5, 1, 2);
    mainLayout->addWidget(itemCombo, 5, 8, 1, 2);
    mainLayout->addWidget(clearItemButton, 5, 10, 1, 2);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(putPlantButton, &QPushButton::clicked,
            this, [=]() {
                int row = sceneRowSpinBox->text().toInt() - 1;
                int col = sceneColSpinBox->text().toInt() - 1;
                int type = plantMenuCombo->currentIndex();
                bool imitater = imitaterCheckBox->isChecked() || type == 48;
                emit Plant(row, col, type, imitater);
            });

    connect(putZombieButton, &QPushButton::clicked,
            this, [=]() {
                int row = sceneRowSpinBox->text().toInt() - 1;
                int col = sceneColSpinBox->text().toInt() - 1;
                int type = zombieMenuCombo->currentIndex();
                emit PutZombie(row, col, type);
            });

    connect(putGraveButton, &QPushButton::clicked,
            this, [=]() {
                int row = sceneRowSpinBox->text().toInt() - 1;
                int col = sceneColSpinBox->text().toInt() - 1;
                emit PutGrave(row, col);
            });

    connect(putRakeButton, &QPushButton::clicked,
            this, [=]() {
                int row = sceneRowSpinBox->text().toInt() - 1;
                int col = sceneColSpinBox->text().toInt() - 1;
                emit PutRake(row, col);
            });

    connect(putCoinButton, &QPushButton::clicked,
            this, [=]() {
                int row = sceneRowSpinBox->text().toInt() - 1;
                int col = sceneColSpinBox->text().toInt() - 1;
                int type = coinTypeCombo->currentIndex() + 1;
                emit PutCoin(row, col, type);
            });

    connect(putLadderButton, &QPushButton::clicked,
            this, [=]() {
                int row = sceneRowSpinBox->text().toInt() - 1;
                int col = sceneColSpinBox->text().toInt() - 1;
                emit PutLadder(row, col);
            });

    connect(autoLadderButton, &QPushButton::clicked,
            this, [=]() {
                bool imitater_pumpkin_only = imitaterPumpkinCheckBox->isChecked();
                emit AutoLadder(imitater_pumpkin_only);
            });

    connect(sceneRowSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &ScenePage::Check);

    connect(sceneColSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &ScenePage::Check);

    connect(blockTypeButton, &QPushButton::clicked,
            this, [=]() {
                int row = sceneRowSpinBox->text().toInt() - 1;
                int col = sceneColSpinBox->text().toInt() - 1;
                // 0 1 2 -> 1 2 3
                int type = blockTypeCombo->currentIndex() + 1;
                emit SetBlockType(row, col, type);
            });

    connect(rowTypeButton, &QPushButton::clicked,
            this, [=]() {
                int row = sceneRowSpinBox->text().toInt() - 1;
                int type = rowTypeCombo->currentIndex();
                emit SetRowType(row, type);
            });

    connect(sceneButton, &QPushButton::clicked,
            this, [=]() {
                int scene = sceneCombo->currentIndex();
                emit SetScene(scene);
            });

    connect(musicButton, &QPushButton::clicked,
            this, [=]() {
                int id = musicCombo->currentIndex() + 1;
                emit SetMusic(id);
            });

    connect(clearItemButton, &QPushButton::clicked,
            this, [=]() {
                int type = itemCombo->currentIndex();
                switch (type)
                {
                case 0:
                    emit ClearItems(1);
                    break;
                case 1:
                    emit ClearItems(2);
                    break;
                case 2:
                    emit ClearItems(3);
                    break;
                case 3:
                    emit ClearItems(4);
                    break;
                case 4:
                    emit ClearItems(5);
                    break;
                case 5:
                    emit ClearItems(7);
                    break;
                case 6:
                    emit ClearItems(10);
                    break;
                case 7:
                    emit ClearItems(11);
                    break;
                case 8:
                    emit ClearItems(12);
                    break;
                case 9:
                    emit ClearAllPlants();
                    break;
                case 10:
                    emit AllZombiesXXX(0);
                    break;
                default:
                    break;
                }
            });

    connect(startLawnMowersButton, &QPushButton::clicked,
            this, &ScenePage::StartLawnMowers);

    connect(clearLawnMowersButton, &QPushButton::clicked,
            this, &ScenePage::ClearLawnMowers);

    connect(resetLawnMowersButton, &QPushButton::clicked,
            this, &ScenePage::ResetLawnMowers);
}

void ScenePage::TranslateUI()
{
    sceneRowLabel->setText(tr("Row") + " (1~6)");
    sceneColLabel->setText(tr("Column") + " (1~9)");

    // SET_COMBO_TEXT(plantMenuCombo, List::Get().seedList, 51);
    if (plantMenuCombo->count() == 0)
        for (size_t i = 0; i < 51; i++)
            plantMenuCombo->addItem(QString("[") + QString::number(i) + "]" + " " + List::Get().seedList[i]);
    else
        for (size_t i = 0; i < 51; i++)
            plantMenuCombo->setItemText(i, QString("[") + QString::number(i) + "]" + " " + List::Get().seedList[i]);

    putPlantButton->setText(tr("Planting"));
    imitaterCheckBox->setText(tr("Imitater"));

    // SET_COMBO_TEXT(zombieMenuCombo, List::Get().zombieList, 33);
    if (zombieMenuCombo->count() == 0)
        for (size_t i = 0; i < 33; i++)
            zombieMenuCombo->addItem(QString("[") + QString::number(i) + "]" + " " + List::Get().zombieList[i]);
    else
        for (size_t i = 0; i < 33; i++)
            zombieMenuCombo->setItemText(i, QString("[") + QString::number(i) + "]" + " " + List::Get().zombieList[i]);

    putZombieButton->setText(tr("Put"));

    putGraveButton->setText(tr("Grave"));
    putRakeButton->setText(tr("Rake"));
    SET_COMBO_TEXT(coinTypeCombo, List::Get().coinList, 27);
    putCoinButton->setText(tr("Coin"));
    putLadderButton->setText(tr("Ladder"));
    autoLadderButton->setText(tr("Ladder Pumpkin"));
    imitaterPumpkinCheckBox->setText(tr("Imitater Pumpkin Only"));

    blockTypeLabel->setText(tr("Block Type"));
    SET_COMBO_TEXT(blockTypeCombo, List::Get().blockTypeList, 3);
    blockTypeButton->setText(tr("Set"));

    rowTypeLabel->setText(tr("Row Type (Spawn)"));
    SET_COMBO_TEXT(rowTypeCombo, List::Get().rowTypeList, 3);
    rowTypeButton->setText(tr("Set"));

    sceneLabel->setText(tr("Game Scene"));

    // SET_COMBO_TEXT(sceneCombo, List::Get().sceneList, 10);
    if (sceneCombo->count() == 0)
        for (size_t i = 0; i < 10; i++)
            sceneCombo->addItem(QString("[") + QString::number(i) + "]" + " " + List::Get().sceneList[i]);
    else
        for (size_t i = 0; i < 10; i++)
            sceneCombo->setItemText(i, QString("[") + QString::number(i) + "]" + " " + List::Get().sceneList[i]);

    sceneButton->setText(tr("Set"));

    startLawnMowersButton->setText(tr("Start Lawn Mowers"));
    clearLawnMowersButton->setText(tr("Clear Lawn Mowers"));
    resetLawnMowersButton->setText(tr("Reset Lawn Mowers"));

    musicLabel->setText(tr("Background Music"));
    SET_COMBO_TEXT(musicCombo, List::Get().musicList, 12);
    musicButton->setText(tr("Set"));

    SET_COMBO_TEXT(itemCombo, List::Get().itemList, 11);
    clearItemButton->setText(tr("Clear"));
}

void ScenePage::Check()
{
    // row : 0 ~ 5
    // col : 0 ~ 8
    // -1 means all
    int row = sceneRowSpinBox->value() - 1;
    int col = sceneColSpinBox->value() - 1;

    if (-1 <= row && row <= 5 && -1 <= col && col <= 8)
    {
        blockTypeLabel->setEnabled(true);
        blockTypeCombo->setEnabled(true);
        blockTypeButton->setEnabled(true);
        if (row != -1 && col != -1)
            emit GetBlockType(row, col);
    }
    else
    {
        blockTypeLabel->setEnabled(false);
        blockTypeCombo->setEnabled(false);
        blockTypeButton->setEnabled(false);
    }

    if (-1 <= row && row <= 5)
    {
        rowTypeLabel->setEnabled(true);
        rowTypeCombo->setEnabled(true);
        rowTypeButton->setEnabled(true);
        if (row != -1)
            emit GetRowType(row);
    }
    else
    {
        rowTypeLabel->setEnabled(false);
        rowTypeCombo->setEnabled(false);
        rowTypeButton->setEnabled(false);
    }
}

void ScenePage::ShowBlock(int type)
{
    blockTypeCombo->setCurrentIndex(type - 1);
}

void ScenePage::ShowRow(int type)
{
    rowTypeCombo->setCurrentIndex(type);
}

void ScenePage::ShowScene(int scene)
{
    if (scene != -1)
        sceneCombo->setCurrentIndex(scene);
}

// Lineup

LineupPage::LineupPage(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<std::string>("std::string");

    quickLineupModeCheckBox = new QCheckBox(this);
    quickPassButton = new QPushButton(this);
    mixModeToSurvivalEndlessButton = new QPushButton(this);
    hiddenSceneLabel = new QLabel(this);

    clearAllGravesButton = new QPushButton(this);
    lilyPadOnPoolButton = new QPushButton(this);
    flowerPotOnRoofButton = new QPushButton(this);
    clearAllPlantsButton = new QPushButton(this);

    lilyPadOnPoolMenu = new QMenu(this);
    for (size_t i = 0; i < 9; i++)
    {
        lilyPadPlantToAction[i] = new QAction(this);
        lilyPadOnPoolMenu->addAction(lilyPadPlantToAction[i]);
    }
    lilyPadOnPoolButton->setMenu(lilyPadOnPoolMenu);

    flowerPotOnRoofMenu = new QMenu(this);
    for (size_t i = 0; i < 9; i++)
    {
        flowerPotPlantToAction[i] = new QAction(this);
        flowerPotOnRoofMenu->addAction(flowerPotPlantToAction[i]);
    }
    flowerPotOnRoofButton->setMenu(flowerPotOnRoofMenu);

    arrayDesignLabel = new QLabel(this);
    updateCheckButton = new QPushButton(this);
    endlessBuildCombo = new QComboBox(this);
    oneKeySetupButton = new QPushButton(this);

    stringTextEdit = new QPlainTextEdit(this);

    string2buildButton = new QPushButton(this);
    build2stringButton = new QPushButton(this);

    copyStringButton = new QPushButton(this);
    pasteStringButton = new QPushButton(this);
    saveStringButton = new QPushButton(this);
    deleteStringButton = new QPushButton(this);

    allowSwitchSceneCheckBox = new QCheckBox(this);
    keepHpStatusCheckBox = new QCheckBox(this);

    hiddenSceneLabel->setOpenExternalLinks(true);
    arrayDesignLabel->setOpenExternalLinks(true);

    deleteStringButton->setEnabled(false);

    stringTextEdit->setLineWrapMode(QPlainTextEdit::WidgetWidth);
    stringTextEdit->setPlainText("0,E 1 1 0 0 0,E 2 1 0 0 0,E 3 1 0 0 0,E 4 1 0 0 0,E 5 1 0 0 0,E 5 2 0 0 0,E 1 5 0 0 0,E 1 4 0 0 0,E 2 4 0 0 0,E 3 4 0 0 0,E 4 4 0 0 0,E 5 4 0 0 0,E 5 5 0 0 0,E 1 7 0 0 0,E 2 7 0 0 0,E 3 8 0 0 0,E 4 9 0 0 0,E 5 9 0 0 0,E 1 9 0 0 0,E 2 9 0 0 0,E 4 7 0 0 0,E 5 7 0 0 0"); // LCX

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(quickLineupModeCheckBox, 0, 0, 1, 3);
    mainLayout->addWidget(quickPassButton, 0, 3, 1, 3);
    mainLayout->addWidget(mixModeToSurvivalEndlessButton, 0, 6, 1, 4);
    mainLayout->addWidget(hiddenSceneLabel, 0, 10, 1, 2);
    mainLayout->addWidget(clearAllGravesButton, 1, 0, 1, 3);
    mainLayout->addWidget(lilyPadOnPoolButton, 1, 3, 1, 3);
    mainLayout->addWidget(flowerPotOnRoofButton, 1, 6, 1, 3);
    mainLayout->addWidget(clearAllPlantsButton, 1, 9, 1, 3);
    mainLayout->addWidget(arrayDesignLabel, 2, 0, 1, 3);
    mainLayout->addWidget(updateCheckButton, 2, 3, 1, 2);
    mainLayout->addWidget(endlessBuildCombo, 2, 5, 1, 4);
    mainLayout->addWidget(oneKeySetupButton, 2, 9, 1, 3);
    mainLayout->addWidget(stringTextEdit, 3, 0, 3, 9); //
    mainLayout->addWidget(string2buildButton, 3, 9, 1, 3);
    mainLayout->addWidget(build2stringButton, 4, 9, 1, 3);
    mainLayout->addWidget(copyStringButton, 6, 0, 1, 2);
    mainLayout->addWidget(pasteStringButton, 6, 2, 1, 2);
    mainLayout->addWidget(saveStringButton, 6, 5, 1, 2);
    mainLayout->addWidget(deleteStringButton, 6, 7, 1, 2);
    mainLayout->addWidget(allowSwitchSceneCheckBox, 5, 9, 1, 3);
    mainLayout->addWidget(keepHpStatusCheckBox, 6, 9, 1, 3);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(quickLineupModeCheckBox, &QCheckBox::clicked,
            this, &LineupPage::SetQuickLineupMode);

    connect(quickPassButton, &QPushButton::clicked,
            this, &LineupPage::QuickPass);

    connect(mixModeToSurvivalEndlessButton, &QPushButton::clicked,
            this, [=]() {
                emit MixMode(13, 0);
            });

    connect(clearAllGravesButton, &QPushButton::clicked,
            this, &LineupPage::ClearAllGraves);

    for (size_t i = 0; i < 9; i++)
    {
        connect(lilyPadPlantToAction[i], &QAction::triggered,
                this, [=]() {
                    emit this->LilyPadOnPool(i + 1);
                });
    }

    for (size_t i = 0; i < 9; i++)
    {
        connect(flowerPotPlantToAction[i], &QAction::triggered,
                this, [=]() {
                    emit this->FlowerPotOnRoof(i + 1);
                });
    }

    connect(clearAllPlantsButton, &QPushButton::clicked,
            this, &LineupPage::ClearAllPlants);

    connect(updateCheckButton, &QPushButton::clicked,
            this, &LineupPage::UpdateLineupString);

    connect(endlessBuildCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                if (index != -1)
                {
                    lastSelectedBuildName = endlessBuildNameList[index];                                // save current selected
                    stringTextEdit->setPlainText(endlessBuildStringList[index]);                        // show string
                    deleteStringButton->setEnabled(endlessBuildGroupList[index] == "v2/Lineup/Custom"); // deleteable
                }
            });

    connect(oneKeySetupButton, &QPushButton::clicked,
            this, [=]() {
                int index = endlessBuildCombo->currentIndex();
                QString string = endlessBuildStringList[index];
                // if (StringCheck(string)) // no need
                {
                    std::string str = string.toStdString();
                    bool switch_scene = allowSwitchSceneCheckBox->isChecked();
#ifdef _DEBUG
                    switch_scene = true;
#endif
                    bool keep_status = false;
                    emit SetLineup(str, switch_scene, keep_status);
                }
            });

    connect(string2buildButton, &QPushButton::clicked,
            this, [=]() {
                QString string = stringTextEdit->toPlainText();
                if (StringCheck(string))
                {
                    std::string str = string.toStdString();
                    bool switch_scene = allowSwitchSceneCheckBox->isChecked();
#ifdef _DEBUG
                    switch_scene = true;
#endif
                    bool keep_status = keepHpStatusCheckBox->isChecked();
                    emit SetLineup(str, switch_scene, keep_status);
                }
                else
                {
                    // 一边说着不要一边试着当成新字符串去布阵
                    emit ShowMessageStatusBar(tr("Wrong string format!"));
                    std::string str = string.toStdString();
                    bool switch_scene = allowSwitchSceneCheckBox->isChecked();
#ifdef _DEBUG
                    switch_scene = true;
#endif
                    emit SetLineup2(str, switch_scene);
                }
            });

    connect(build2stringButton, &QPushButton::clicked,
            this, [=]() {
                bool ignore_hp = keepHpStatusCheckBox->isChecked();
                emit GetLineup(ignore_hp);
            });

    connect(copyStringButton, &QPushButton::clicked,
            this, [=]() {
                QString text = stringTextEdit->toPlainText();
                QClipboard *clipboard = QApplication::clipboard();
                if (StringCheck(text))
                {
                    clipboard->setText(QString::fromStdString(ConvertLineup(text.toStdString())));
                    emit ShowMessageStatusBar(tr("Already copied to new format."));
                }
                else
                {
                    clipboard->setText(text);
                    emit ShowMessageStatusBar(tr("Already copied."));
                }
            });

    connect(pasteStringButton, &QPushButton::clicked,
            this, [=]() {
                QClipboard *clipboard = QApplication::clipboard();
                QString text = clipboard->text();

                // 去除首尾的空格和任意位置的空白字符
                // 中间的字符会被替换成单个空格, 再把逗号旁边多余的空格去掉
                text = text.simplified();
                text.replace(QString(" ,"), QString(","));
                text.replace(QString(", "), QString(","));

                // 看起来像新格式的话把所有空格都去掉
                if (text[0] == "L")
                    text.remove(QRegExp("\\s"));

                stringTextEdit->setPlainText(text);
                emit ShowMessageStatusBar(tr("Already pasted."));
            });

    connect(saveStringButton, &QPushButton::clicked,
            this, &LineupPage::SaveLineupString);

    connect(deleteStringButton, &QPushButton::clicked,
            this, &LineupPage::DeleteLineupString);

    RefreshLineupString();
}

void LineupPage::TranslateUI()
{
    quickLineupModeCheckBox->setText(tr("Quick Lineup Mode"));
    quickPassButton->setText(tr("Quick Pass"));
    mixModeToSurvivalEndlessButton->setText(tr("Mix Mode To Survival Endless"));
    hiddenSceneLabel->setText(tr("<style>a {text-decoration: none}</style><a href='https://pvz.lmintlcx.com/pvztoolsdemo/hiddenscene/'>Hidden Scene</a>"));

    quickLineupModeCheckBox->setStatusTip(tr("Turn on a series of features that are convenient for manual lineup."));
    quickPassButton->setStatusTip(tr("Kill all zombies and end current level directly with 8000 sunshine and 2020 flags."));

    clearAllGravesButton->setText(tr("Clear All Graves"));
    lilyPadOnPoolButton->setText(tr("Lily Pad On Pool"));
    flowerPotOnRoofButton->setText(tr("Flower Pot On Roof"));
    clearAllPlantsButton->setText(tr("Clear All Plants"));

    for (size_t i = 0; i < 9; i++)
        lilyPadPlantToAction[i]->setText(QString("1 -> ") + QString::number(i + 1));

    for (size_t i = 0; i < 9; i++)
        flowerPotPlantToAction[i]->setText(QString("1 -> ") + QString::number(i + 1));

    arrayDesignLabel->setText(tr("<style>a {text-decoration: none}</style><a href='https://pvz.lmintlcx.com/lineup/'>Open Array Design</a>"));
    updateCheckButton->setText(tr("Update"));
    oneKeySetupButton->setText(tr("One Key Setup"));

    string2buildButton->setText(tr("String -> Lineup"));
    build2stringButton->setText(tr("String <- Lineup"));

    copyStringButton->setText(tr("Copy"));
    pasteStringButton->setText(tr("Paste"));
    saveStringButton->setText(tr("Save"));
    deleteStringButton->setText(tr("Delete"));

    allowSwitchSceneCheckBox->setText(tr("Allow Switch Scene"));
    keepHpStatusCheckBox->setText(tr("Keep HP Status"));
}

bool LineupPage::StringCheck(const QString &text)
{
    QRegExp reg("[0-5](,[a-fA-F0-9]{1,2} [1-6] [1-9] [0-2] [0-4]( [a-zA-Z0-9]{1,}){0,}){0,}");
    return reg.exactMatch(text);
    // return true;
}

std::string LineupPage::ConvertLineup(const std::string &str)
{
    auto split = [](const std::string &str, char seperator) -> std::vector<std::string> {
        std::vector<std::string> result;
        std::string::size_type prev = 0, pos = 0;
        while ((pos = str.find(seperator, pos)) != std::string::npos)
        {
            std::string sub_string(str.substr(prev, pos - prev));
            result.push_back(sub_string);
            prev = ++pos;
        }
        result.push_back(str.substr(prev, pos - prev));
        return result;
    };

    auto hex2dec = [](const std::string &str) -> long {
        char *ptr;
        long num;
        num = strtol(str.c_str(), &ptr, 16);
        return num;
    };

    const bool may_sleep[] = {false, false, false, false, false, false, false, false,
                              true, true, true, false, true, true, true, true,
                              false, false, false, false, false, false, false, false,
                              true, false, false, false, false, false, false, true,
                              false, false, false, false, false, false, false, false,
                              false, false, true, false, false, false, false, false};

    uint16_t items[6 * 9] = {0};
    uint8_t rake_row = 0, scene = 2;

    std::vector<std::string> str_list = split(str, ',');
    size_t count = str_list.size() - 1;

    std::string str_scene = str_list[0];
    if (str_scene == "0") // pool
        scene = 2;
    else if (str_scene == "1") // fog
        scene = 3;
    else if (str_scene == "2") // day
        scene = 0;
    else if (str_scene == "3") // night
        scene = 1;
    else if (str_scene == "4") // roof
        scene = 4;
    else if (str_scene == "5") // moon
        scene = 5;

    uint16_t plant[6 * 9] = {0};
    uint16_t plant_im[6 * 9] = {0};
    uint16_t plant_awake[6 * 9] = {0};
    uint16_t base[6 * 9] = {0};
    uint16_t base_im[6 * 9] = {0};
    uint16_t pumpkin[6 * 9] = {0};
    uint16_t pumpkin_im[6 * 9] = {0};
    uint16_t coffee[6 * 9] = {0};
    uint16_t coffee_im[6 * 9] = {0};
    uint16_t ladder[6 * 9] = {0};

    for (size_t i = 0; i < count; i++)
    {
        std::vector<std::string> item_str = split(str_list[i + 1], ' ');
        int item_type = hex2dec(item_str[0]);

        if (item_type < 0 || item_type > 0x32)
            continue;

        if (item_type == 16 || item_type == 33) // 睡莲 花盆
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            base[item_row * 9 + item_col] = (item_type == 16) ? 1 : 2;
            base_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 50) // 墓碑
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            base[item_row * 9 + item_col] = 3;
            base_im[item_row * 9 + item_col] = 0;
        }
        else if (item_type == 30) // 南瓜
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            pumpkin[item_row * 9 + item_col] = 1;
            pumpkin_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 35) // 咖啡
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            bool item_imitater = item_str[5] == "1";
            coffee[item_row * 9 + item_col] = 1;
            coffee_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
        }
        else if (item_type == 48) // 梯子 0x30
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            ladder[item_row * 9 + item_col] = 1;
        }
        else if (item_type == 49) // 钉耙 0x31
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            rake_row = item_row + 1;
        }
        else // 主要植物
        {
            int item_row = atoi(item_str[1].c_str()) - 1;
            int item_col = atoi(item_str[2].c_str()) - 1;
            int item_state_row = atoi(item_str[3].c_str());
            bool item_imitater = item_str[5] == "1";
            plant[item_row * 9 + item_col] = item_type + 1;
            plant_im[item_row * 9 + item_col] = item_imitater ? 1 : 0;
            plant_awake[item_row * 9 + item_col] = ((scene == 0 || scene == 2 || scene == 4) && may_sleep[item_type] && item_state_row == 0) ? 0 : 1;
        }
    }

    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            uint16_t item = 0;
            item += 0b1111110000000000 & (plant[r * 9 + c] << 10);
            item += 0b0000001000000000 & (plant_im[r * 9 + c] << 9);
            item += 0b0000000100000000 & (plant_awake[r * 9 + c] << 8);
            item += 0b0000000011000000 & (base[r * 9 + c] << 6);
            item += 0b0000000000100000 & (base_im[r * 9 + c] << 5);
            item += 0b0000000000010000 & (pumpkin[r * 9 + c] << 4);
            item += 0b0000000000001000 & (pumpkin_im[r * 9 + c] << 3);
            item += 0b0000000000000100 & (coffee[r * 9 + c] << 2);
            item += 0b0000000000000010 & (coffee_im[r * 9 + c] << 1);
            item += 0b0000000000000001 & (ladder[r * 9 + c] << 0);
            items[r * 9 + c] = item;
        }
    }

    // #ifdef _DEBUG
    //     std::cout << std::endl;
    //     for (int r = 0; r < 6; r++)
    //     {
    //         for (int c = 0; c < 9; c++)
    //             std::cout << std::bitset<16>(items[r * 9 + c]) << " ";
    //         std::cout << std::endl;
    //     }
    //     std::cout << std::bitset<8>((rake_row << 4) | (scene & 0b00001111));
    //     std::cout << std::endl;
    // #endif

    unsigned long size = 121; // compressBound(6*9*2)
    unsigned char lineup_bin[128] = {0};
    unsigned long cut_size = ((scene == 2 || scene == 3) ? 6 : 5) * 9 * sizeof(uint16_t);
    compress2(lineup_bin, &size, (unsigned char *)items, cut_size, Z_BEST_COMPRESSION);
    lineup_bin[size - 1 + 1] = (rake_row << 4) | (scene & 0b00001111);

    for (size_t i = 0; i < size + 1; i++)
        lineup_bin[i] = lineup_bin[i] ^ (unsigned char)0x54;

    DWORD len = 256;
    char lineup_str[256] = {0};
    CryptBinaryToStringA(lineup_bin, size + 1, CRYPT_STRING_BASE64, lineup_str, &len);

    std::string lineup(lineup_str);
    lineup.erase(std::remove(lineup.begin(), lineup.end(), '\r'), lineup.end());
    lineup.erase(std::remove(lineup.begin(), lineup.end(), '\n'), lineup.end());
    // std::cout << lineup << " " << lineup.size() << std::endl;

    return lineup;
}

void LineupPage::ShowLineup(std::string str)
{
    QString text = QString::fromStdString(str);
    stringTextEdit->clear();
    stringTextEdit->setPlainText(text);
}

void LineupPage::InitLineupString(QString str)
{
    QString content;
    if (str == "")
    {
        QFile file(":/res/lineup_string.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        content = file.readAll();
        file.close();
    }
    else
    {
        content = str;
    }
    // std::wcout << content.toStdWString().c_str();

    QJsonParseError parse_json_err;
    QJsonDocument document = QJsonDocument::fromJson(content.toUtf8(), &parse_json_err);
    if (parse_json_err.error != QJsonParseError::NoError)
        return;

    QJsonObject json_object = document.object();
    // qDebug() << "json_object[version] = " << json_object["version"].toInt();
    // qDebug() << "json_object[author] = " << json_object["author"].toString();

    if (!(json_object.contains(QStringLiteral("lineup"))))
        return;

    QJsonValue array_value = json_object.value(QStringLiteral("lineup"));
    if (!(array_value.isArray()))
        return;
    QJsonArray array = array_value.toArray();

    QSettings settings;
    settings.setValue("v2/LineupVersion", json_object["version"].toInt());
    settings.remove("v2/Lineup/Official");
    settings.beginGroup("v2/Lineup/Official");
    for (int i = 0; i < array.size(); i++)
    {
        QJsonValue arr = array.at(i);
        QJsonObject key = arr.toObject();
        // qDebug() << "key[name] = " << key["name"].toString();
        // qDebug() << "key[string] = " << key["string"].toString();
        QString uuid = QUuid::createUuid().toString();
        settings.beginGroup(uuid);
        settings.setValue("Name", key["name"].toString());
        settings.setValue("String", key["string"].toString());
        settings.endGroup();
    }
    settings.endGroup();
}

void LineupPage::RefreshLineupString()
{
    QStringList lineup_stringlist;

    QStringList groups;
    groups << "v2/Lineup/Official"
           << "v2/Lineup/Custom";

    QSettings settings;
    foreach (QString group, groups)
    {
        settings.beginGroup(group);
        foreach (QString uuid, settings.childGroups())
        {
            settings.beginGroup(uuid);
            QString name = settings.value("Name", QString("")).toString();
            QString string = settings.value("String", QString("")).toString();
            QString lineup_string = QString("") + group + "|" + uuid + "|" + name + "|" + string;
            lineup_stringlist << lineup_string;
            settings.endGroup();
        }
        settings.endGroup();
    }

    auto LessThan = [&](const QString &s1, const QString &s2) {
        auto GetWeight = [&](const QString &s) {
            //    场地 1000000000000
            // 2F 春哥 10000000000
            // 2A 曾哥 100000000
            // 1E 南瓜 1000000
            // 10 睡莲 10000
            // 21 花盆 100
            // 30 梯子 1
            long long w = 0;
            QStringList items = s.split("|")[3].split(",");
            for (int i = 0; i < items.size(); i++)
            {
                if (i == 0) // scene
                {
                    int scene = items[i].toInt();
                    switch (scene)
                    {
                    case 0: // pool
                        w += 2 * 1000000000000;
                        break;
                    case 1: // fog
                        w += 3 * 1000000000000;
                        break;
                    case 2: // day
                        w += 0 * 1000000000000;
                        break;
                    case 3: // night
                        w += 1 * 1000000000000;
                        break;
                    case 4: // roof
                        w += 4 * 1000000000000;
                        break;
                    case 5: // moon
                        w += 5 * 1000000000000;
                        break;
                    default:
                        break;
                    }
                }
                else
                {
                    QString plant = items[i].split(" ")[0];
                    if (plant == "2F") // Cob Cannon
                        w += 10000000000;
                    else if (plant == "2A") // Gloom-shroom
                        w += 100000000;
                    else if (plant == "1E")
                        w += 1000000;
                    else if (plant == "10")
                        w += 10000;
                    else if (plant == "21")
                        w += 100;
                    else if (plant == "30")
                        w += 1;
                }
            }
            return w;
        };
        return GetWeight(s1) < GetWeight(s2);
    };
    std::sort(lineup_stringlist.begin(), lineup_stringlist.end(), LessThan);
    // qDebug() << lineup_stringlist;

    endlessBuildGroupList.clear();
    endlessBuildUuidList.clear();
    endlessBuildNameList.clear();
    endlessBuildStringList.clear();
    for (int i = 0; i < lineup_stringlist.size(); i++)
    {
        QStringList strs = lineup_stringlist[i].split("|");
        QString group = strs[0];
        QString uuid = strs[1];
        QString name = strs[2];
        QString string = strs[3];
        endlessBuildGroupList << group;
        endlessBuildUuidList << uuid;
        endlessBuildNameList << name;
        endlessBuildStringList << string;
    }
    // qDebug() << endlessBuildNameList;
    // qDebug() << endlessBuildStringList;
    endlessBuildCombo->blockSignals(true); // hack
    endlessBuildCombo->clear();
    endlessBuildCombo->addItems(endlessBuildNameList);
    endlessBuildCombo->blockSignals(false); // hack

    if (lastSelectedBuildName.isEmpty())
        lastSelectedBuildName = QString("[PE].经典八炮");
    int index = endlessBuildNameList.indexOf(lastSelectedBuildName);
    // qDebug() << index << lastSelectedBuildName;
    if (index != -1)
        endlessBuildCombo->setCurrentIndex(index);
}

void LineupPage::UpdateLineupString()
{
    lastSelectedBuildName = endlessBuildCombo->currentText(); // save current selected

    updateCheckButton->setEnabled(false);
    endlessBuildCombo->setEnabled(false);
    oneKeySetupButton->setEnabled(false);

    auto decompress_gzip = [&](const QByteArray &gzip_data) -> QByteArray {
        QByteArray raw_data;

        const int CHUNK_SIZE = 1024 * 16;
        unsigned char buffer[CHUNK_SIZE];

        z_stream gzip_stream;
        gzip_stream.zalloc = Z_NULL;
        gzip_stream.zfree = Z_NULL;
        gzip_stream.opaque = Z_NULL;
        gzip_stream.avail_in = gzip_data.size();
        gzip_stream.next_in = (Bytef *)(gzip_data.data());

        int status = inflateInit2(&gzip_stream, MAX_WBITS + 16); // gzip decoding
        if (status != Z_OK)
            return QByteArray();

        do // run inflate()
        {
            // memset(buffer, 0, CHUNK_SIZE);
            gzip_stream.avail_out = CHUNK_SIZE;
            gzip_stream.next_out = buffer;
            int status = inflate(&gzip_stream, Z_NO_FLUSH);
            switch (status)
            {
            case Z_NEED_DICT:
            case Z_DATA_ERROR:
            case Z_STREAM_ERROR:
            case Z_MEM_ERROR:
                inflateEnd(&gzip_stream);
                return QByteArray();
            default:
                raw_data.append((char *)buffer, CHUNK_SIZE - gzip_stream.avail_out);
                // qDebug() << raw_data.size();
            }
        } while (status == Z_OK && status != Z_STREAM_END && gzip_stream.avail_out == 0);
        // 3->1 should be ok
        // } while (status == Z_OK);
        // } while (status != Z_STREAM_END);
        // } while (gzip_stream.avail_out == 0);

        inflateEnd(&gzip_stream);
        return raw_data;
    };

    QNetworkAccessManager manager;
    QNetworkRequest request;
    request.setUrl(QUrl("https://pvz.lmintlcx.com/getpvztools/lineup_string.json"));
    request.setRawHeader("User-Agent", PRODUCT_NAME "/" VERSION_NAME " "
                                                    "(" COMPANY_NAME ")");
    request.setRawHeader("Accept-Encoding", "gzip, deflate");
    request.setRawHeader("Cache-Control", "no-cache");
    QNetworkReply *reply = manager.get(request);

    // while (!reply->isFinished())
    //     qApp->processEvents();
    QEventLoop loop;
    connect(reply, &QNetworkReply::finished,
            &loop, &QEventLoop::quit);
    // connect(reply, &QNetworkReply::downloadProgress,
    //         [=](qint64 bytesReceived, qint64 bytesTotal) {
    //             qDebug() << "total: " << bytesTotal << " "
    //                      << "received: " << bytesReceived;
    //         });
    loop.exec();

    if (manager.networkAccessible() == QNetworkAccessManager::NotAccessible)
    {
        emit ShowMessageStatusBar(tr("Unable to connect to network."));
        reply->deleteLater();
        updateCheckButton->setEnabled(true);
        endlessBuildCombo->setEnabled(true);
        oneKeySetupButton->setEnabled(true);
        return;
    }

    if (reply->error() == QNetworkReply::NoError)
    {
        QString lineup_string;
        QByteArray content = reply->readAll();
        if (reply->hasRawHeader("Content-Encoding") && reply->rawHeader("Content-Encoding") == "gzip" //
            && (unsigned char)content.at(0) == 0x1F && (unsigned char)content.at(1) == 0x8B)          //
            lineup_string = decompress_gzip(content);
        else
            lineup_string = content;
        // std::wcout << lineup_string.toStdWString().c_str();
        // qDebug() << lineup_string.size();

        QJsonParseError parse_json_err;
        QJsonDocument document = QJsonDocument::fromJson(lineup_string.toUtf8(), &parse_json_err);
        if (parse_json_err.error != QJsonParseError::NoError)
        {
            emit ShowMessageStatusBar(tr("Update failed, lineup string database parsing error."));
        }
        else
        {
            QJsonObject json_object = document.object();
            QString author = json_object["author"].toString();
            int version = json_object["version"].toInt();
            int counts = json_object["counts"].toInt();
            // qDebug() << author << version << counts;
            QSettings settings;
            int lineup_version = settings.value("v2/LineupVersion", 0).toInt();
            settings.beginGroup("v2/Lineup/Official");
            QStringList groups = settings.childGroups();
            int lineup_counts = groups.size();
            settings.endGroup();
            if (author == "lmintlcx" && (version > lineup_version || counts != lineup_counts))
            {
                InitLineupString(lineup_string);
                RefreshLineupString();
                emit ShowMessageStatusBar(tr("Lineup string updated, version %1, total %2.").arg(version).arg(counts));
            }
            else
            {
                emit ShowMessageStatusBar(tr("Lineup already up to date, version %1, total %2.").arg(lineup_version).arg(lineup_counts));
            }
        }
    }
    else
    {
        emit ShowMessageStatusBar(tr("Error while connecting to update server."));
    }

    reply->deleteLater();

    updateCheckButton->setEnabled(true);
    endlessBuildCombo->setEnabled(true);
    oneKeySetupButton->setEnabled(true);
}

void LineupPage::SaveLineupString()
{
    QString string = stringTextEdit->toPlainText();
    if (!StringCheck(string))
    {
        emit ShowMessageStatusBar(tr("Wrong string format!"));
        return;
    }

    QString name_header = "";
    int scene = string.split(",")[0].toInt();
    switch (scene)
    {
    case 0: // pool
        name_header = "[PE].";
        break;
    case 1: // fog
        name_header = "[FE].";
        break;
    case 2: // day
        name_header = "[DE].";
        break;
    case 3: // night
        name_header = "[NE].";
        break;
    case 4: // roof
        name_header = "[RE].";
        break;
    case 5: // moon
        name_header = "[ME].";
        break;
    default:
        break;
    }

    bool ok;
    QString name = QInputDialog::getText(this,                            //
                                         tr("Name"),                      //
                                         tr("Please input lineup name:"), //
                                         QLineEdit::Normal,               //
                                         name_header,                     //
                                         &ok,                             //
                                         Qt::WindowCloseButtonHint);      //

    if (ok && !name.isEmpty())
    {
        if (name.contains("|"))
        {
            ShowMessageStatusBar(tr("Save failed, name cannot contain character \"|\"."));
            return;
        }
        QSettings settings;
        QString uuid = QUuid::createUuid().toString();
        settings.beginGroup("v2/Lineup/Custom");
        settings.beginGroup(uuid);
        settings.setValue("Name", name);
        settings.setValue("String", string);
        settings.endGroup();
        settings.endGroup();
        emit ShowMessageStatusBar(tr("Lineup %1 already saved.").arg(name));
        lastSelectedBuildName = name; //  save current selected
        RefreshLineupString();
    }
}

void LineupPage::DeleteLineupString()
{
    QString name = endlessBuildCombo->currentText();

    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Warning"));
    msgBox.setText(tr("Are you sure you want to delete lineup %1?").arg(name));
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::Yes);
    int ret = msgBox.exec();
    if (ret == QMessageBox::Yes)
    {
        int index = endlessBuildCombo->currentIndex();
        QString group = endlessBuildGroupList[index];
        QString uuid = endlessBuildUuidList[index];
        QString name = endlessBuildNameList[index]; //
        QString string = endlessBuildStringList[index];

        endlessBuildGroupList.removeAt(index);
        endlessBuildUuidList.removeAt(index);
        endlessBuildNameList.removeAt(index);
        endlessBuildStringList.removeAt(index);

        endlessBuildCombo->removeItem(index);

        QSettings settings;
        settings.remove(group + "/" + uuid);

        emit ShowMessageStatusBar(tr("Lineup %1 already deleted.").arg(name));
    }
}

void LineupPage::KeepSelectedFeatures()
{
    if (quickLineupModeCheckBox->isChecked())
        emit SetQuickLineupMode(true);
}

// Garden

GardenPage::GardenPage(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<std::vector<GardenPlant>>("std::vector<GardenPlant>");

    fertilizerUnlimitedCheckBox = new QCheckBox(this);
    bugSprayUnlimitedCheckBox = new QCheckBox(this);
    chocolateUnlimitedCheckBox = new QCheckBox(this);
    treeFoodUnlimitedCheckBox = new QCheckBox(this);

    treeHeightLabel = new QLabel(this);
    treeHeightLineEdit = new QLineEdit(this);
    treeHeightLineEdit->setValidator(new QIntValidator(0, 999999999, this));
    treeHeightButton = new QPushButton(this);

    table = new QTableWidget(this);
    table->setColumnCount(8);
    table->setRowCount(0); // 4 x 8 + 8 + 8 + 1
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->hideColumn(0); // hide index
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    table->resizeColumnsToContents();
    table->resizeRowsToContents();

    clearButton = new QPushButton(this);
    loadButton = new QPushButton(this);
    setButton = new QPushButton(this);

    sceneLabel = new QLabel(this);
    typeLabel = new QLabel(this);
    directionLabel = new QLabel(this);
    colorLabel = new QLabel(this);
    statusLabel = new QLabel(this);

    sceneCombo = new QComboBox(this);
    typeCombo = new QComboBox(this);
    directionCombo = new QComboBox(this);
    colorCombo = new QComboBox(this);
    statusCombo = new QComboBox(this);

    // default status
    sceneCombo->setEnabled(false);
    typeCombo->setEnabled(false);
    directionCombo->setEnabled(false);
    colorCombo->setEnabled(false);
    statusCombo->setEnabled(false);

    treeHeightLineEdit->setText("1000");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(fertilizerUnlimitedCheckBox, 0, 0, 1, 3);
    mainLayout->addWidget(bugSprayUnlimitedCheckBox, 0, 3, 1, 3);
    mainLayout->addWidget(chocolateUnlimitedCheckBox, 0, 6, 1, 3);
    mainLayout->addWidget(treeFoodUnlimitedCheckBox, 0, 9, 1, 3);
    mainLayout->addWidget(treeHeightLabel, 1, 0, 1, 2);
    mainLayout->addWidget(treeHeightLineEdit, 1, 2, 1, 2);
    mainLayout->addWidget(treeHeightButton, 1, 4, 1, 2);
    mainLayout->addWidget(clearButton, 1, 6, 1, 2);
    mainLayout->addWidget(loadButton, 1, 8, 1, 2);
    mainLayout->addWidget(setButton, 1, 10, 1, 2);
    mainLayout->addWidget(table, 2, 0, 5, 8);
    mainLayout->addWidget(sceneLabel, 2, 8, 1, 1);
    mainLayout->addWidget(typeLabel, 3, 8, 1, 1);
    mainLayout->addWidget(directionLabel, 4, 8, 1, 1);
    mainLayout->addWidget(colorLabel, 5, 8, 1, 1);
    mainLayout->addWidget(statusLabel, 6, 8, 1, 1);
    mainLayout->addWidget(sceneCombo, 2, 9, 1, 3);
    mainLayout->addWidget(typeCombo, 3, 9, 1, 3);
    mainLayout->addWidget(directionCombo, 4, 9, 1, 3);
    mainLayout->addWidget(colorCombo, 5, 9, 1, 3);
    mainLayout->addWidget(statusCombo, 6, 9, 1, 3);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(fertilizerUnlimitedCheckBox, &QCheckBox::clicked,
            this, &GardenPage::FertilizerUnlimited);

    connect(bugSprayUnlimitedCheckBox, &QCheckBox::clicked,
            this, &GardenPage::BugSprayUnlimited);

    connect(chocolateUnlimitedCheckBox, &QCheckBox::clicked,
            this, &GardenPage::ChocolateUnlimited);

    connect(treeFoodUnlimitedCheckBox, &QCheckBox::clicked,
            this, &GardenPage::TreeFoodUnlimited);

    connect(treeHeightButton, &QPushButton::clicked,
            this, [=]() {
                int height = treeHeightLineEdit->text().toInt();
                emit SetTreeHeight(height);
            });

    connect(table, &QTableWidget::itemSelectionChanged,
            this, [=]() {
                sceneCombo->blockSignals(true);
                typeCombo->blockSignals(true);
                directionCombo->blockSignals(true);
                colorCombo->blockSignals(true);
                statusCombo->blockSignals(true);

                QList<QTableWidgetItem *> items = table->selectedItems();
                int count = items.count();
                for (int i = 0; i < count; i++)
                {
                    QTableWidgetItem *item = items.at(i);
                    QString text = item->text();
                    // int row = table->row(item);
                    int col = table->column(item);
                    if (col == 3)
                    {
                        int index = List::Get().gardenSceneList.indexOf(text);
                        sceneCombo->setCurrentIndex(index);
                    }
                    else if (col == 4)
                    {
                        int index = List::Get().seedList.indexOf(text);
                        typeCombo->setCurrentIndex(index);
                    }
                    else if (col == 5)
                    {
                        int index = List::Get().directionList.indexOf(text);
                        directionCombo->setCurrentIndex(index);
                    }
                    else if (col == 6)
                    {
                        int index = List::Get().colorList.indexOf(text);
                        colorCombo->setCurrentIndex(index);
                    }
                    else if (col == 7)
                    {
                        int index = List::Get().plantStatusList.indexOf(text);
                        statusCombo->setCurrentIndex(index);
                    }
                }

                sceneCombo->blockSignals(false);
                typeCombo->blockSignals(false);
                directionCombo->blockSignals(false);
                colorCombo->blockSignals(false);
                statusCombo->blockSignals(false);

                sceneCombo->setEnabled(true);
                typeCombo->setEnabled(true);
                directionCombo->setEnabled(true);
                colorCombo->setEnabled(true);
                statusCombo->setEnabled(true);
            });

    connect(sceneCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &GardenPage::UpdateContent);

    connect(typeCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &GardenPage::UpdateContent);

    connect(directionCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &GardenPage::UpdateContent);

    connect(colorCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &GardenPage::UpdateContent);

    connect(statusCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &GardenPage::UpdateContent);

    connect(clearButton, &QPushButton::clicked,
            this, [=]() {
                table->clearContents();
                table->setRowCount(0);
                table->horizontalHeader()->setVisible(false);
            });

    connect(loadButton, &QPushButton::clicked,
            this, [=]() {
                table->clearContents();
                table->setRowCount(0);
                table->horizontalHeader()->setVisible(false);

                sceneCombo->setEnabled(false);
                typeCombo->setEnabled(false);
                directionCombo->setEnabled(false);
                colorCombo->setEnabled(false);
                statusCombo->setEnabled(false);

                emit GetGardenPlants();
            });

    connect(setButton, &QPushButton::clicked,
            this, [=]() {
                std::vector<GardenPlant> plants;

                int count = table->rowCount();
                for (int r = 0; r < count; r++)
                {
                    GardenPlant plant;
                    plant.index = table->item(r, 0)->text().toInt() - 1;
                    plant.row = table->item(r, 1)->text().toInt() - 1;
                    plant.col = table->item(r, 2)->text().toInt() - 1;
                    plant.scene = List::Get().gardenSceneList.indexOf(table->item(r, 3)->text());
                    plant.type = List::Get().seedList.indexOf(table->item(r, 4)->text());
                    plant.direction = List::Get().directionList.indexOf(table->item(r, 5)->text());
                    plant.color = List::Get().colorList.indexOf(table->item(r, 6)->text());
                    plant.status = List::Get().plantStatusList.indexOf(table->item(r, 7)->text());
                    plants.push_back(plant);
                }

                if (count > 0)
                    emit SetGardenPlants(plants);
            });
}

void GardenPage::TranslateUI()
{
    fertilizerUnlimitedCheckBox->setText(tr("Fertilizer Unlimited"));
    bugSprayUnlimitedCheckBox->setText(tr("Bug Spray Unlimited"));
    chocolateUnlimitedCheckBox->setText(tr("Chocolate Unlimited"));
    treeFoodUnlimitedCheckBox->setText(tr("Tree Food Unlimited"));

    treeHeightLabel->setText(tr("Tree Height"));
    treeHeightButton->setText(tr("Set"));

    clearButton->setText(tr("Clear"));
    loadButton->setText(tr("Load"));
    setButton->setText(tr("Set"));

    sceneLabel->setText(tr("Scene"));
    typeLabel->setText(tr("Type"));
    directionLabel->setText(tr("Direction"));
    colorLabel->setText(tr("Color"));
    statusLabel->setText(tr("Status"));

    SET_COMBO_TEXT(sceneCombo, List::Get().gardenSceneList, 4);
    SET_COMBO_TEXT(typeCombo, List::Get().seedList, 48);
    SET_COMBO_TEXT(directionCombo, List::Get().directionList, 2);
    SET_COMBO_TEXT(colorCombo, List::Get().colorList, 13);
    SET_COMBO_TEXT(statusCombo, List::Get().plantStatusList, 4);

    table->setHorizontalHeaderLabels(List::Get().gardenHeadersList);

    if (table->rowCount() > 0)
        emit loadButton->clicked();
}

void GardenPage::ShowGardenPlants(std::vector<GardenPlant> plants)
{
    size_t count = plants.size();
    table->setRowCount(count);

    if (count > 0)
        table->horizontalHeader()->setVisible(true);

    for (size_t r = 0; r < count; r++)
    {
        GardenPlant plant = plants[r];
        QString index = QString::number(plant.index + 1);
        QString row = QString::number(plant.row + 1);
        QString col = QString::number(plant.col + 1);
        QString type = List::Get().seedList[plant.type];
        QString scene = List::Get().gardenSceneList[plant.scene];
        QString direction = List::Get().directionList[plant.direction];
        QString color = List::Get().colorList[plant.color];
        QString status = List::Get().plantStatusList[plant.status];

        table->setItem(r, 0, new QTableWidgetItem(index));
        table->setItem(r, 1, new QTableWidgetItem(row));
        table->setItem(r, 2, new QTableWidgetItem(col));
        table->setItem(r, 3, new QTableWidgetItem(scene));
        table->setItem(r, 4, new QTableWidgetItem(type));
        table->setItem(r, 5, new QTableWidgetItem(direction));
        table->setItem(r, 6, new QTableWidgetItem(color));
        table->setItem(r, 7, new QTableWidgetItem(status));
    }

    table->resizeColumnsToContents();
    table->resizeRowsToContents();
}

void GardenPage::KeepSelectedFeatures()
{
    if (fertilizerUnlimitedCheckBox->isChecked())
        emit FertilizerUnlimited(true);

    if (bugSprayUnlimitedCheckBox->isChecked())
        emit BugSprayUnlimited(true);

    if (chocolateUnlimitedCheckBox->isChecked())
        emit ChocolateUnlimited(true);

    if (treeFoodUnlimitedCheckBox->isChecked())
        emit TreeFoodUnlimited(true);
}

void GardenPage::UpdateContent()
{
    QList<QTableWidgetItem *> items = table->selectedItems();
    int count = items.count();
    for (int i = 0; i < count; i++)
    {
        QTableWidgetItem *item = items.at(i);
        // int row = table->row(item);
        int col = table->column(item);
        if (col == 3)
            item->setText(List::Get().gardenSceneList[sceneCombo->currentIndex()]);
        else if (col == 4)
            item->setText(List::Get().seedList[typeCombo->currentIndex()]);
        else if (col == 5)
            item->setText(List::Get().directionList[directionCombo->currentIndex()]);
        else if (col == 6)
            item->setText(List::Get().colorList[colorCombo->currentIndex()]);
        else if (col == 7)
            item->setText(List::Get().plantStatusList[statusCombo->currentIndex()]);
    }
}

// Vase

VasePage::VasePage(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<std::vector<Vase>>("std::vector<Vase>");

    vaseCountLabel = new QLabel(this);
    clearButton = new QPushButton(this);
    loadButton = new QPushButton(this);
    setButton = new QPushButton(this);

    table = new QTableWidget(this);
    table->setColumnCount(6);
    table->setRowCount(0); // 6 x 9
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(false);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->hideColumn(0); // hide index
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    table->resizeColumnsToContents();
    table->resizeRowsToContents();

    rowLabel = new QLabel(this);
    colLabel = new QLabel(this);
    vaseSkinLabel = new QLabel(this);
    vaseTypeLabel = new QLabel(this);
    vaseContentPlantLabel = new QLabel(this);
    vaseContentZombieLabel = new QLabel(this);
    vaseContentSunLabel = new QLabel(this);

    rowCombo = new QComboBox(this);
    colCombo = new QComboBox(this);
    vaseSkinCombo = new QComboBox(this);
    vaseTypeCombo = new QComboBox(this);
    vaseContentPlantCombo = new QComboBox(this);
    vaseContentZombieCombo = new QComboBox(this);
    vaseContentSunLineEdit = new QLineEdit(this);
    vaseContentSunLineEdit->setValidator(new QIntValidator(0, 99, this));

    // set default status
    rowCombo->setEnabled(false);
    colCombo->setEnabled(false);
    vaseSkinCombo->setEnabled(false);
    vaseTypeCombo->setEnabled(false);
    vaseContentPlantCombo->setEnabled(false);
    vaseContentZombieCombo->setEnabled(false);
    vaseContentSunLineEdit->setEnabled(false);

    vaseContentSunLineEdit->setText("3");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(vaseCountLabel, 0, 0, 1, 4);
    mainLayout->addWidget(clearButton, 0, 6, 1, 2);
    mainLayout->addWidget(loadButton, 0, 8, 1, 2);
    mainLayout->addWidget(setButton, 0, 10, 1, 2);
    mainLayout->addWidget(table, 1, 0, 6, 8);
    mainLayout->addWidget(rowLabel, 1, 8, 1, 1);
    mainLayout->addWidget(colLabel, 1, 10, 1, 1);
    mainLayout->addWidget(vaseSkinLabel, 2, 8, 1, 1);
    mainLayout->addWidget(vaseTypeLabel, 3, 8, 1, 1);
    mainLayout->addWidget(vaseContentPlantLabel, 4, 8, 1, 1);
    mainLayout->addWidget(vaseContentZombieLabel, 5, 8, 1, 1);
    mainLayout->addWidget(vaseContentSunLabel, 6, 8, 1, 1);
    mainLayout->addWidget(rowCombo, 1, 9, 1, 1);
    mainLayout->addWidget(colCombo, 1, 11, 1, 1);
    mainLayout->addWidget(vaseSkinCombo, 2, 9, 1, 3);
    mainLayout->addWidget(vaseTypeCombo, 3, 9, 1, 3);
    mainLayout->addWidget(vaseContentPlantCombo, 4, 9, 1, 3);
    mainLayout->addWidget(vaseContentZombieCombo, 5, 9, 1, 3);
    mainLayout->addWidget(vaseContentSunLineEdit, 6, 9, 1, 3);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(rowCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &VasePage::UpdateContent);

    connect(colCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &VasePage::UpdateContent);

    connect(vaseSkinCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &VasePage::UpdateContent);

    connect(vaseTypeCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &VasePage::UpdateContent);

    connect(vaseContentPlantCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &VasePage::UpdateContent);

    connect(vaseContentZombieCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &VasePage::UpdateContent);

    connect(vaseContentSunLineEdit, &QLineEdit::textChanged,
            this, &VasePage::UpdateContent);

    connect(clearButton, &QPushButton::clicked,
            this, [=]() {
                table->clearContents();
                table->setRowCount(0);
                table->horizontalHeader()->setVisible(false);

                vaseCountLabel->setText(tr("Vase Count") + ": " + "0");
            });

    connect(loadButton, &QPushButton::clicked,
            this, [=]() {
                table->clearContents();
                table->setRowCount(0);
                table->horizontalHeader()->setVisible(false);

                rowCombo->setEnabled(false);
                colCombo->setEnabled(false);
                vaseSkinCombo->setEnabled(false);
                vaseTypeCombo->setEnabled(false);
                vaseContentPlantCombo->setEnabled(false);
                vaseContentZombieCombo->setEnabled(false);
                vaseContentSunLineEdit->setEnabled(false);

                emit GetVases();
            });

    connect(setButton, &QPushButton::clicked,
            this, [=]() {
                std::vector<Vase> vases;

                int count = table->rowCount();
                for (int r = 0; r < count; r++)
                {
                    Vase vase;
                    vase.index = table->item(r, 0)->text().toInt() - 1;
                    vase.row = table->item(r, 1)->text().toInt() - 1;
                    vase.col = table->item(r, 2)->text().toInt() - 1;
                    vase.skin = List::Get().vaseSkinList.indexOf(table->item(r, 3)->text()) + 3 - 1;
                    vase.type = List::Get().vaseTypeList.indexOf(table->item(r, 4)->text());
                    if (vase.type == 1) // Plant
                        vase.content_plant = List::Get().seedList.indexOf(table->item(r, 5)->text());
                    else if (vase.type == 2) // Zombie
                        vase.content_zombie = List::Get().zombieList.indexOf(table->item(r, 5)->text());
                    else if (vase.type == 3) // Sun
                        vase.content_sun = table->item(r, 5)->text().toInt();
                    // else if (vase.type == 0) // Empty
                    vases.push_back(vase);
                }

                if (count > 0)
                    emit SetVases(vases);
            });

    connect(table, &QTableWidget::itemSelectionChanged,
            this, [=]() {
                rowCombo->blockSignals(true);
                colCombo->blockSignals(true);
                vaseSkinCombo->blockSignals(true);
                vaseTypeCombo->blockSignals(true);
                vaseContentPlantCombo->blockSignals(true);
                vaseContentZombieCombo->blockSignals(true);
                vaseContentSunLineEdit->blockSignals(true);

                QList<QTableWidgetItem *> items = table->selectedItems();
                int count = items.count();
                for (int i = 0; i < count; i++)
                {
                    QTableWidgetItem *item = items.at(i);
                    QString text = item->text();
                    int row = table->row(item);
                    int col = table->column(item);
                    if (col == 1)
                    {
                        int index = text.toInt() - 1;
                        rowCombo->setCurrentIndex(index);
                    }
                    else if (col == 2)
                    {
                        int index = text.toInt() - 1;
                        colCombo->setCurrentIndex(index);
                    }
                    else if (col == 3)
                    {
                        int index = List::Get().vaseSkinList.indexOf(text);
                        vaseSkinCombo->setCurrentIndex(index);
                    }
                    else if (col == 4)
                    {
                        int index = List::Get().vaseTypeList.indexOf(text);
                        vaseTypeCombo->setCurrentIndex(index);
                        SetComboEnabled();
                    }
                    else if (col == 5)
                    {
                        QString type = table->item(row, col - 1)->text();
                        if (type == List::Get().vaseTypeList[1]) // Plant
                        {
                            int index = List::Get().seedList.indexOf(text);
                            vaseContentPlantCombo->setCurrentIndex(index);
                        }
                        else if (type == List::Get().vaseTypeList[2]) // Zombie
                        {
                            int index = List::Get().zombieList.indexOf(text);
                            vaseContentZombieCombo->setCurrentIndex(index);
                        }
                        else if (type == List::Get().vaseTypeList[3]) // Sun
                        {
                            vaseContentSunLineEdit->setText(text);
                        }
                        //  else if (type == List::Get().vaseTypeList[0]) // Empty
                    }
                }

                rowCombo->blockSignals(false);
                colCombo->blockSignals(false);
                vaseSkinCombo->blockSignals(false);
                vaseTypeCombo->blockSignals(false);
                vaseContentPlantCombo->blockSignals(false);
                vaseContentZombieCombo->blockSignals(false);
                vaseContentSunLineEdit->blockSignals(false);

                rowCombo->setEnabled(true);
                colCombo->setEnabled(true);
                vaseSkinCombo->setEnabled(true);
                vaseTypeCombo->setEnabled(true);
                // vaseContentPlantCombo->setEnabled(true);
                // vaseContentZombieCombo->setEnabled(true);
                // vaseContentSunLineEdit->setEnabled(true);
            });

    connect(vaseTypeCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, &VasePage::SetComboEnabled);
}

void VasePage::TranslateUI()
{
    vaseCountLabel->setText(tr("Vase Count") + ": " + "0");
    clearButton->setText(tr("Clear"));
    loadButton->setText(tr("Load"));
    setButton->setText(tr("Set"));

    rowLabel->setText(tr("Row"));
    colLabel->setText(tr("Column"));
    vaseSkinLabel->setText(tr("Skin"));
    vaseTypeLabel->setText(tr("Type"));
    vaseContentPlantLabel->setText(tr("Plant"));
    vaseContentZombieLabel->setText(tr("Zombie"));
    vaseContentSunLabel->setText(tr("Sun"));

    if (rowCombo->count() == 0)
        for (size_t i = 0; i < 6; i++)
            rowCombo->addItem(QString::number(i + 1));
    else
        for (size_t i = 0; i < 6; i++)
            rowCombo->setItemText(i, QString::number(i + 1));

    if (colCombo->count() == 0)
        for (size_t i = 0; i < 9; i++)
            colCombo->addItem(QString::number(i + 1));
    else
        for (size_t i = 0; i < 9; i++)
            colCombo->setItemText(i, QString::number(i + 1));

    SET_COMBO_TEXT(vaseSkinCombo, List::Get().vaseSkinList, 4);
    SET_COMBO_TEXT(vaseTypeCombo, List::Get().vaseTypeList, 4);
    SET_COMBO_TEXT(vaseContentPlantCombo, List::Get().seedList, 53);
    SET_COMBO_TEXT(vaseContentZombieCombo, List::Get().zombieList, 33);

    table->setHorizontalHeaderLabels(List::Get().vaseHeadersList);

    if (table->rowCount() > 0)
        emit loadButton->clicked();
}

void VasePage::ShowVases(std::vector<Vase> vases)
{
    size_t count = vases.size();
    table->setRowCount(count);

    vaseCountLabel->setText(tr("Vase Count") + ": " + QString::number(count));

    if (count > 0)
        table->horizontalHeader()->setVisible(true);

    for (size_t r = 0; r < count; r++)
    {
        Vase vase = vases[r];
        QString index = QString::number(vase.index + 1);
        QString row = QString::number(vase.row + 1);
        QString col = QString::number(vase.col + 1);
        QString skin = List::Get().vaseSkinList[vase.skin - 3 + 1];
        QString type = List::Get().vaseTypeList[vase.type];
        QString content;
        if (vase.type == 1) // Plant
            content = List::Get().seedList[vase.content_plant];
        else if (vase.type == 2) // Zombie
            content = List::Get().zombieList[vase.content_zombie];
        else if (vase.type == 3) // Sun
            content = QString::number(vase.content_sun);
        else // if (vase.type == 0) // Empty
            content = tr("Empty");

        table->setItem(r, 0, new QTableWidgetItem(index));
        table->setItem(r, 1, new QTableWidgetItem(row));
        table->setItem(r, 2, new QTableWidgetItem(col));
        table->setItem(r, 3, new QTableWidgetItem(skin));
        table->setItem(r, 4, new QTableWidgetItem(type));
        table->setItem(r, 5, new QTableWidgetItem(content));
    }

    table->resizeColumnsToContents();
    table->resizeRowsToContents();
}

void VasePage::UpdateContent()
{
    QList<QTableWidgetItem *> items = table->selectedItems();
    int count = items.count();
    for (int i = 0; i < count; i++)
    {
        QTableWidgetItem *item = items.at(i);
        // int row = table->row(item);
        int col = table->column(item);
        if (col == 1)
            item->setText(rowCombo->currentText());
        else if (col == 2)
            item->setText(colCombo->currentText());
        else if (col == 3)
            item->setText(List::Get().vaseSkinList[vaseSkinCombo->currentIndex()]);
        else if (col == 4)
            item->setText(List::Get().vaseTypeList[vaseTypeCombo->currentIndex()]);
        else if (col == 5)
        {
            if (vaseTypeCombo->currentIndex() == 0)
                item->setText(tr("Empty"));
            else if (vaseTypeCombo->currentIndex() == 1)
                item->setText(List::Get().seedList[vaseContentPlantCombo->currentIndex()]);
            else if (vaseTypeCombo->currentIndex() == 2)
                item->setText(List::Get().zombieList[vaseContentZombieCombo->currentIndex()]);
            else if (vaseTypeCombo->currentIndex() == 3)
                item->setText(vaseContentSunLineEdit->text());
        }
    }
}

void VasePage::SetComboEnabled()
{
    int index = vaseTypeCombo->currentIndex();
    if (index == 0)
    {
        vaseContentPlantCombo->setEnabled(false);
        vaseContentZombieCombo->setEnabled(false);
        vaseContentSunLineEdit->setEnabled(false);
    }
    else if (index == 1)
    {
        vaseContentPlantCombo->setEnabled(true);
        vaseContentZombieCombo->setEnabled(false);
        vaseContentSunLineEdit->setEnabled(false);
    }
    else if (index == 2)
    {
        vaseContentPlantCombo->setEnabled(false);
        vaseContentZombieCombo->setEnabled(true);
        vaseContentSunLineEdit->setEnabled(false);
    }
    else if (index == 3)
    {
        vaseContentPlantCombo->setEnabled(false);
        vaseContentZombieCombo->setEnabled(false);
        vaseContentSunLineEdit->setEnabled(true);
    }
}

// Effects

EffectPage::EffectPage(QWidget *parent)
    : QWidget(parent)
{
    sukhbirCodeButton = new QPushButton(this);
    futureCodeButton = new QPushButton(this);
    mustacheCodeButton = new QPushButton(this);
    trickedoutCodeButton = new QPushButton(this);
    daisiesCodeButton = new QPushButton(this);
    danceCodeButton = new QPushButton(this);
    pinataCodeButton = new QPushButton(this);
    konamiCodeButton = new QPushButton(this);

    itsRainingCheckBox = new QCheckBox(this);
    littleZombieCheckBox = new QCheckBox(this);
    columnLikeCheckBox = new QCheckBox(this);
    zombieQuickCheckBox = new QCheckBox(this);
    whackZombieCheckBox = new QCheckBox(this);
    highGravityCheckBox = new QCheckBox(this);
    graveDangerCheckBox = new QCheckBox(this);
    stormyNightCheckBox = new QCheckBox(this);
    bungeeBlitzCheckBox = new QCheckBox(this);

    iceTrailLabel = new QLabel(this);
    iceTrailCombo = new QComboBox(this);
    iceTrailLineEdit = new QLineEdit(this);
    iceTrailLineEdit->setValidator(new QIntValidator(-9999, 9999, this));
    iceTrailLineEdit->setAlignment(Qt::AlignRight);
    iceTrailButton = new QPushButton(this);

    fullFogCheckBox = new QCheckBox(this);
    noFogCheckBox = new QCheckBox(this);
    seeVaseCheckBox = new QCheckBox(this);

    sukhbirCodeButton->setText("SUKHBIR");
    futureCodeButton->setText("FUTURE");
    mustacheCodeButton->setText("MUSTACHE");
    trickedoutCodeButton->setText("TRICKEDOUT");
    daisiesCodeButton->setText("DAISIES");
    danceCodeButton->setText("DANCE");
    pinataCodeButton->setText("PINATA");
    konamiCodeButton->setText("KONAMI");

    iceTrailLineEdit->setText("800");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(sukhbirCodeButton, 0, 0, 1, 3);
    mainLayout->addWidget(futureCodeButton, 0, 3, 1, 3);
    mainLayout->addWidget(mustacheCodeButton, 0, 6, 1, 3);
    mainLayout->addWidget(trickedoutCodeButton, 0, 9, 1, 3);
    mainLayout->addWidget(daisiesCodeButton, 1, 0, 1, 3);
    mainLayout->addWidget(danceCodeButton, 1, 3, 1, 3);
    mainLayout->addWidget(pinataCodeButton, 1, 6, 1, 3);
    mainLayout->addWidget(konamiCodeButton, 1, 9, 1, 3);
    mainLayout->addWidget(itsRainingCheckBox, 2, 0, 1, 4);
    mainLayout->addWidget(littleZombieCheckBox, 2, 4, 1, 4);
    mainLayout->addWidget(columnLikeCheckBox, 2, 8, 1, 4);
    mainLayout->addWidget(zombieQuickCheckBox, 3, 0, 1, 4);
    mainLayout->addWidget(whackZombieCheckBox, 3, 4, 1, 4);
    mainLayout->addWidget(highGravityCheckBox, 3, 8, 1, 4);
    mainLayout->addWidget(graveDangerCheckBox, 4, 0, 1, 4);
    mainLayout->addWidget(stormyNightCheckBox, 4, 4, 1, 4);
    mainLayout->addWidget(bungeeBlitzCheckBox, 4, 8, 1, 4);
    mainLayout->addWidget(iceTrailLabel, 5, 0, 1, 3);
    mainLayout->addWidget(iceTrailCombo, 5, 3, 1, 3);
    mainLayout->addWidget(iceTrailLineEdit, 5, 6, 1, 3);
    mainLayout->addWidget(iceTrailButton, 5, 9, 1, 3);
    mainLayout->addWidget(fullFogCheckBox, 6, 0, 1, 4);
    mainLayout->addWidget(noFogCheckBox, 6, 4, 1, 4);
    mainLayout->addWidget(seeVaseCheckBox, 6, 8, 1, 4);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(sukhbirCodeButton, &QPushButton::clicked,
            this, [=]() {
                emit WisdomTreeCode(0);
            });

    connect(futureCodeButton, &QPushButton::clicked,
            this, [=]() {
                emit WisdomTreeCode(5);
            });

    connect(mustacheCodeButton, &QPushButton::clicked,
            this, [=]() {
                emit WisdomTreeCode(20);
            });

    connect(trickedoutCodeButton, &QPushButton::clicked,
            this, [=]() {
                emit WisdomTreeCode(48);
            });

    connect(daisiesCodeButton, &QPushButton::clicked,
            this, [=]() {
                emit WisdomTreeCode(99);
            });

    connect(danceCodeButton, &QPushButton::clicked,
            this, [=]() {
                emit WisdomTreeCode(500);
            });

    connect(pinataCodeButton, &QPushButton::clicked,
            this, [=]() {
                emit WisdomTreeCode(999);
            });

    connect(konamiCodeButton, &QPushButton::clicked,
            this, [=]() {
                emit KonamiCode();
            });

    connect(itsRainingCheckBox, &QCheckBox::clicked,
            this, &EffectPage::ItsRaining);

    connect(littleZombieCheckBox, &QCheckBox::clicked,
            this, &EffectPage::LittleZombie);

    connect(columnLikeCheckBox, &QCheckBox::clicked,
            this, &EffectPage::ColumnLike);

    connect(zombieQuickCheckBox, &QCheckBox::clicked,
            this, &EffectPage::ZombieQuick);

    connect(whackZombieCheckBox, &QCheckBox::clicked,
            this, &EffectPage::WhackZombie);

    connect(highGravityCheckBox, &QCheckBox::clicked,
            this, &EffectPage::HighGravity);

    connect(graveDangerCheckBox, &QCheckBox::clicked,
            this, &EffectPage::GraveDanger);

    connect(stormyNightCheckBox, &QCheckBox::clicked,
            this, &EffectPage::StormyNight);

    connect(bungeeBlitzCheckBox, &QCheckBox::clicked,
            this, &EffectPage::BungeeBlitz);

    connect(iceTrailCombo, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
            this, [=](int index) {
                if (index != 0)
                {
                    int row = index - 1;
                    emit GetIceTrailX(row);
                }
                else
                {
                    iceTrailLineEdit->setText(QString::number(800));
                }
            });

    connect(iceTrailButton, &QPushButton::clicked,
            this, [=]() {
                int row = iceTrailCombo->currentIndex() - 1;
                int x = iceTrailLineEdit->text().toInt();
                emit SetIceTrailX(row, x);
            });

    connect(fullFogCheckBox, &QCheckBox::clicked,
            this, &EffectPage::FullFog);

    connect(noFogCheckBox, &QCheckBox::clicked,
            this, &EffectPage::NoFog);

    connect(seeVaseCheckBox, &QCheckBox::clicked,
            this, &EffectPage::SeeVase);
}

void EffectPage::TranslateUI()
{
    itsRainingCheckBox->setText(List::Get().miniGamesList[19 - 16]);
    littleZombieCheckBox->setText(List::Get().miniGamesList[25 - 16]);
    columnLikeCheckBox->setText(List::Get().miniGamesList[27 - 16]);
    zombieQuickCheckBox->setText(List::Get().miniGamesList[29 - 16]);
    whackZombieCheckBox->setText(List::Get().miniGamesList[30 - 16]);
    highGravityCheckBox->setText(List::Get().miniGamesList[44 - 16]);
    graveDangerCheckBox->setText(List::Get().miniGamesList[45 - 16]);
    stormyNightCheckBox->setText(List::Get().miniGamesList[47 - 16]);
    bungeeBlitzCheckBox->setText(List::Get().miniGamesList[48 - 16]);

    iceTrailLabel->setText(tr("Ice Trail Coordinate"));
    SET_COMBO_TEXT(iceTrailCombo, List::Get().rowList, 7);
    iceTrailButton->setText(tr("Set"));

    fullFogCheckBox->setText(tr("Full Fog"));
    noFogCheckBox->setText(tr("No Fog"));
    seeVaseCheckBox->setText(tr("See Vase"));
}

void EffectPage::ShowIceTrailX(int x)
{
    iceTrailLineEdit->setText(QString::number(x));
}

void EffectPage::SetQuickLineupMode(bool on)
{
    if (on)
    {
        noFogCheckBox->setEnabled(false);
        emit NoFog(true);
    }
    else
    {
        noFogCheckBox->setEnabled(true);
        emit NoFog(noFogCheckBox->isChecked());
    }
}

void EffectPage::KeepSelectedFeatures()
{
    if (itsRainingCheckBox->isChecked())
        emit ItsRaining(true);

    if (littleZombieCheckBox->isChecked())
        emit LittleZombie(true);

    if (columnLikeCheckBox->isChecked())
        emit ColumnLike(true);

    if (zombieQuickCheckBox->isChecked())
        emit ZombieQuick(true);

    if (whackZombieCheckBox->isChecked())
        emit WhackZombie(true);

    if (highGravityCheckBox->isChecked())
        emit HighGravity(true);

    if (graveDangerCheckBox->isChecked())
        emit GraveDanger(true);

    if (stormyNightCheckBox->isChecked())
        emit StormyNight(true);

    if (bungeeBlitzCheckBox->isChecked())
        emit BungeeBlitz(true);

    if (fullFogCheckBox->isChecked())
        emit FullFog(true);

    if (noFogCheckBox->isChecked())
        emit NoFog(true);

    if (seeVaseCheckBox->isChecked())
        emit SeeVase(true);
}

// Others

OthersPage::OthersPage(QWidget *parent)
    : QWidget(parent)
{
    disableSaveDataCheckBox = new QCheckBox(this);
    disableDeleteDataCheckBox = new QCheckBox(this);

    runningInBackgroundCheckBox = new QCheckBox(this);
    disablePauseCheckBox = new QCheckBox(this);

    openDataDirButton = new QPushButton(this);

    debugModeLabel = new QLabel(this);
    debugModeCombo = new QComboBox(this);
    debugModeButton = new QPushButton(this);

    openPakFileButton = new QPushButton(this);
    pakFileLineEdit = new QLineEdit(this);
    unpackPakButton = new QPushButton(this);

    openPakFolderButton = new QPushButton(this);
    pakPathLineEdit = new QLineEdit(this);
    packPakButton = new QPushButton(this);

    targetMapButton = new QPushButton(this);
    cannonLauncherButton = new QPushButton(this);
    portalButton = new QPushButton(this);
    izeLineupButton = new QPushButton(this);

    // default

    runningInBackgroundCheckBox->setChecked(true);

    pakFileLineEdit->setText("");
    pakPathLineEdit->setText("");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(disableSaveDataCheckBox, 0, 0, 1, 3);
    mainLayout->addWidget(disableDeleteDataCheckBox, 0, 3, 1, 3);
    mainLayout->addWidget(runningInBackgroundCheckBox, 0, 6, 1, 3);
    mainLayout->addWidget(disablePauseCheckBox, 0, 9, 1, 3);
    mainLayout->addWidget(openDataDirButton, 1, 0, 1, 3);
    mainLayout->addWidget(debugModeLabel, 1, 4, 1, 2);
    mainLayout->addWidget(debugModeCombo, 1, 6, 1, 3);
    mainLayout->addWidget(debugModeButton, 1, 9, 1, 3);
    mainLayout->addWidget(openPakFileButton, 2, 0, 1, 2);
    mainLayout->addWidget(pakFileLineEdit, 2, 2, 1, 8);
    mainLayout->addWidget(unpackPakButton, 2, 10, 1, 2);
    mainLayout->addWidget(openPakFolderButton, 3, 0, 1, 2);
    mainLayout->addWidget(pakPathLineEdit, 3, 2, 1, 8);
    mainLayout->addWidget(packPakButton, 3, 10, 1, 2);
    mainLayout->addWidget(targetMapButton, 4, 0, 1, 3);
    mainLayout->addWidget(cannonLauncherButton, 4, 3, 1, 3);
    mainLayout->addWidget(portalButton, 4, 6, 1, 3);
    mainLayout->addWidget(izeLineupButton, 4, 9, 1, 3);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(openPakFileButton, &QPushButton::clicked,
            this, &OthersPage::GetFileName);

    connect(openPakFolderButton, &QPushButton::clicked,
            this, &OthersPage::GetFolderName);

    connect(disableSaveDataCheckBox, &QCheckBox::clicked,
            this, &OthersPage::DisableSaveData);

    connect(disableDeleteDataCheckBox, &QCheckBox::clicked,
            this, &OthersPage::DisableDeleteData);

    connect(runningInBackgroundCheckBox, &QCheckBox::clicked,
            this, &OthersPage::RunningInBackground);

    connect(disablePauseCheckBox, &QCheckBox::clicked,
            this, &OthersPage::DisablePause);

    connect(openDataDirButton, &QPushButton::clicked,
            this, &OthersPage::OpenDataDir);

    connect(debugModeButton, &QPushButton::clicked,
            this, [=]() {
                int mode = debugModeCombo->currentIndex();
                emit DebugMode(mode);
            });

    connect(unpackPakButton, &QPushButton::clicked,
            this, [=]() {
                QString file_name = pakFileLineEdit->text();
                QString dir_name = pakPathLineEdit->text();
                if (file_name.size() > 0 && dir_name.size() > 0)
                {
                    unpackPakButton->setEnabled(false);
                    packPakButton->setEnabled(false);
                    emit UnpackPAK(file_name, dir_name);
                }
            });

    connect(packPakButton, &QPushButton::clicked,
            this, [=]() {
                QString dir_name = pakPathLineEdit->text();
                if (dir_name.size() > 0)
                {
                    unpackPakButton->setEnabled(false);
                    packPakButton->setEnabled(false);
                    emit PackPAK(dir_name);
                }
            });

    connect(targetMapButton, &QPushButton::clicked,
            this, &OthersPage::ShowTargetMapPage);

    connect(cannonLauncherButton, &QPushButton::clicked,
            this, &OthersPage::ShowCannonLauncherPage);

    connect(portalButton, &QPushButton::clicked,
            this, &OthersPage::ShowPortalPage);

    connect(izeLineupButton, &QPushButton::clicked,
            this, &OthersPage::ShowIzeLineupPage);

    setAcceptDrops(true);
}

void OthersPage::TranslateUI()
{
    disableSaveDataCheckBox->setText(tr("Disable Save Data"));
    disableDeleteDataCheckBox->setText(tr("Disable Delete Data"));

    runningInBackgroundCheckBox->setText(tr("Running In Background"));
    disablePauseCheckBox->setText(tr("Disable Pause"));

    openDataDirButton->setText(tr("Open Data Dir"));

    debugModeLabel->setText(tr("Debug Mode"));
    SET_COMBO_TEXT(debugModeCombo, List::Get().debugModeList, 5);
    debugModeButton->setText(tr("Set"));

    openPakFileButton->setText(tr("Open File"));
    unpackPakButton->setText(tr("Unpack"));

    openPakFolderButton->setText(tr("Open Folder"));
    packPakButton->setText(tr("Pack"));

    targetMapButton->setText(tr("Target Map Modify"));
    cannonLauncherButton->setText(tr("Cannon Launcher"));
    portalButton->setText(tr("Portal"));
    izeLineupButton->setText(tr("I, Zombie Endless"));
}

void OthersPage::GetFileName()
{
    QString file_name = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        ".",
        tr("PAK files (*.pak) ;; All files (*.*)"));
    if (!file_name.isNull())
    {
        pakFileLineEdit->setText(file_name);
        pakPathLineEdit->setText(QCoreApplication::applicationDirPath() + "/" + QString::number(QDateTime::currentDateTime().toTime_t(), 16));
    }
}

void OthersPage::GetFolderName()
{
    QString dir_name = QFileDialog::getExistingDirectory(
        this,
        tr("Open Folder"),
        ".");
    if (!dir_name.isNull())
        pakPathLineEdit->setText(dir_name);
}

void OthersPage::UnpackFinished()
{
    unpackPakButton->setEnabled(true);
    packPakButton->setEnabled(true);
}

void OthersPage::PackFinished()
{
    unpackPakButton->setEnabled(true);
    packPakButton->setEnabled(true);
}

void OthersPage::KeepSelectedFeatures()
{
    if (disableSaveDataCheckBox->isChecked())
        emit DisableSaveData(true);

    if (disableDeleteDataCheckBox->isChecked())
        emit DisableDeleteData(true);

    if (runningInBackgroundCheckBox->isChecked())
        emit RunningInBackground(true);

    if (disablePauseCheckBox->isChecked())
        emit DisablePause(true);
}

void OthersPage::dragEnterEvent(QDragEnterEvent *event)
{
    if (true)
        event->acceptProposedAction();
}

void OthersPage::dropEvent(QDropEvent *event)
{
    QList<QUrl> urls = event->mimeData()->urls();
    if (urls.isEmpty())
        return;

    QString first_file_name = urls.first().toLocalFile();
    if (first_file_name.isEmpty())
        return;

    foreach (QUrl u, urls)
    {
        // qDebug() << u.toString().mid(8).toStdString().c_str();
        QString input_url = u.toString().mid(8);
        QFileInfo input_url_info(input_url);

        if (input_url_info.isFile() && input_url_info.suffix() == "pak") // pak file
        {
            pakFileLineEdit->setText(input_url);
            pakPathLineEdit->setText(QCoreApplication::applicationDirPath() + "/" + QString::number(QDateTime::currentDateTime().toTime_t(), 16));
        }
        else if (input_url_info.isDir()) // folder
        {
            pakPathLineEdit->setText(input_url);
        }
    }
    // qDebug() << urls.size();
}

// Status

StatusPage::StatusPage(QWidget *parent)
    : QWidget(parent)
{
    gameModeTextLabel = new QLabel(this);

    refreshStatusTimer = new QTimer(this);
    refreshStatusTimer->setInterval(100);
    autoRefreshCheckBox = new QCheckBox(this);
    refreshIntervalSpinBox = new QSpinBox(this);
    refreshIntervalSpinBox->setRange(0, 999999);
    refreshIntervalSpinBox->setSingleStep(1);
    refreshIntervalSpinBox->setValue(10);

    gameModeLabel = new QLabel(this);
    gameModeValueLabel = new QLabel(this);
    gameUiLabel = new QLabel(this);
    gameUiValueLabel = new QLabel(this);

    runningTimeLabel = new QLabel(this);
    runningTimeValueLabel = new QLabel(this);
    levelCompletedLabel = new QLabel(this);
    levelCompletedValueLabel = new QLabel(this);

    totalWavesLabel = new QLabel(this);
    totalWavesValueLabel = new QLabel(this);
    pastWavesLabel = new QLabel(this);
    pastWavesValueLabel = new QLabel(this);

    totalHpLabel = new QLabel(this);
    totalHpValueLabel = new QLabel(this);
    triggerHpLabel = new QLabel(this);
    triggerHpValueLabel = new QLabel(this);

    countdownLabel = new QLabel(this);
    countdownValueLabel = new QLabel(this);
    hugewaveCountdownLabel = new QLabel(this);
    hugewaveCountdownValueLabel = new QLabel(this);

    plantCountLabel = new QLabel(this);
    plantCountValueLabel = new QLabel(this);
    zombieCountLabel = new QLabel(this);
    zombieCountValueLabel = new QLabel(this);

    gameModeTextLabel->setText("");

    gameModeValueLabel->setText("0");
    gameUiValueLabel->setText("0");
    runningTimeValueLabel->setText("0");
    levelCompletedValueLabel->setText("0");
    totalWavesValueLabel->setText("0");
    pastWavesValueLabel->setText("0");
    totalHpValueLabel->setText("0");
    triggerHpValueLabel->setText("0");
    countdownValueLabel->setText("0");
    hugewaveCountdownValueLabel->setText("0");
    plantCountValueLabel->setText("0");
    zombieCountValueLabel->setText("0");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(gameModeTextLabel, 0, 0, 1, 3);
    mainLayout->addWidget(autoRefreshCheckBox, 0, 3, 1, 2);
    mainLayout->addWidget(refreshIntervalSpinBox, 0, 5, 1, 1);
    mainLayout->addWidget(gameModeLabel, 1, 0, 1, 2);
    mainLayout->addWidget(gameModeValueLabel, 1, 2, 1, 1);
    mainLayout->addWidget(gameUiLabel, 1, 3, 1, 2);
    mainLayout->addWidget(gameUiValueLabel, 1, 5, 1, 1);
    mainLayout->addWidget(runningTimeLabel, 2, 0, 1, 2);
    mainLayout->addWidget(runningTimeValueLabel, 2, 2, 1, 1);
    mainLayout->addWidget(levelCompletedLabel, 2, 3, 1, 2);
    mainLayout->addWidget(levelCompletedValueLabel, 2, 5, 1, 1);
    mainLayout->addWidget(totalWavesLabel, 3, 0, 1, 2);
    mainLayout->addWidget(totalWavesValueLabel, 3, 2, 1, 1);
    mainLayout->addWidget(pastWavesLabel, 3, 3, 1, 2);
    mainLayout->addWidget(pastWavesValueLabel, 3, 5, 1, 1);
    mainLayout->addWidget(totalHpLabel, 4, 0, 1, 2);
    mainLayout->addWidget(totalHpValueLabel, 4, 2, 1, 1);
    mainLayout->addWidget(triggerHpLabel, 4, 3, 1, 2);
    mainLayout->addWidget(triggerHpValueLabel, 4, 5, 1, 1);
    mainLayout->addWidget(countdownLabel, 5, 0, 1, 2);
    mainLayout->addWidget(countdownValueLabel, 5, 2, 1, 1);
    mainLayout->addWidget(hugewaveCountdownLabel, 5, 3, 1, 2);
    mainLayout->addWidget(hugewaveCountdownValueLabel, 5, 5, 1, 1);
    mainLayout->addWidget(plantCountLabel, 6, 0, 1, 2);
    mainLayout->addWidget(plantCountValueLabel, 6, 2, 1, 1);
    mainLayout->addWidget(zombieCountLabel, 6, 3, 1, 2);
    mainLayout->addWidget(zombieCountValueLabel, 6, 5, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(autoRefreshCheckBox, &QCheckBox::stateChanged,
            this, [=](int state) {
                if (state == Qt::Checked)
                    refreshStatusTimer->start();
                else
                    refreshStatusTimer->stop();
            });

    connect(refreshIntervalSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, [=](int value) {
                refreshStatusTimer->setInterval(value * 10);
            });

    connect(refreshStatusTimer, &QTimer::timeout,
            this, &StatusPage::GetStatus);
}

void StatusPage::TranslateUI()
{
    autoRefreshCheckBox->setText(tr("Auto Refresh"));

    gameModeLabel->setText(tr("Game Mode"));
    gameUiLabel->setText(tr("Game UI"));
    runningTimeLabel->setText(tr("Running Time"));
    levelCompletedLabel->setText(tr("Level Completed"));
    totalWavesLabel->setText(tr("Total Waves"));
    pastWavesLabel->setText(tr("Past Waves"));
    totalHpLabel->setText(tr("Total HP"));
    triggerHpLabel->setText(tr("Trigger HP"));
    countdownLabel->setText(tr("Count Down"));
    hugewaveCountdownLabel->setText(tr("Huge Wave Count Down"));
    plantCountLabel->setText(tr("Plant Count"));
    zombieCountLabel->setText(tr("Zombie Count"));
}

void StatusPage::ShowStatus(std::array<int, 12> status)
{
    // Adventure  // 0
    // Mini-Games // 16-50
    // Puzzle     // 51-72
    // Survival   // 1-15
    int mode = status[0];
    if (mode == 0)
        gameModeTextLabel->setText(tr("Adventure"));
    else if (mode >= 1 && mode < 16)
        gameModeTextLabel->setText(List::Get().survivalList[mode - 1]);
    else if (mode >= 16 && mode < 51)
        gameModeTextLabel->setText(List::Get().miniGamesList[mode - 16]);
    else // if (mode >= 51 && mode < 73)
        gameModeTextLabel->setText(List::Get().puzzleList[mode - 51]);

    QString countdown = QString::number(status[8]);
    QString hugewave_countdown = QString::number(status[9]);
    if (status[8] > 0 && status[8] < 200)
        countdown = QString("<p style=\"color:red\">") + countdown + QString("</p>");
    if (status[9] > 0 && status[9] < 200)
        hugewave_countdown = QString("<p style=\"color:red\">") + hugewave_countdown + QString("</p>");

    gameModeValueLabel->setText(QString::number(status[0]));
    gameUiValueLabel->setText(QString::number(status[1]));
    runningTimeValueLabel->setText(QString::number(status[2]));
    levelCompletedValueLabel->setText(QString::number(status[3]));
    totalWavesValueLabel->setText(QString::number(status[4]));
    pastWavesValueLabel->setText(QString::number(status[5]));
    totalHpValueLabel->setText(QString::number(status[6]));
    triggerHpValueLabel->setText(QString::number(status[7]));
    countdownValueLabel->setText(countdown);
    hugewaveCountdownValueLabel->setText(hugewave_countdown);
    plantCountValueLabel->setText(QString::number(status[10]));
    zombieCountValueLabel->setText(QString::number(status[11]));
}

bool StatusPage::IsAutoRefresh()
{
    return autoRefreshCheckBox->isChecked();
}

void StatusPage::StartTimer()
{
    refreshStatusTimer->start();
}

void StatusPage::StopTimer(bool uncheck_it)
{
    if (uncheck_it)
        autoRefreshCheckBox->setChecked(false);
    else
        refreshStatusTimer->stop();
}

// SpawnCount

SpawnCountPage::SpawnCountPage(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<std::array<uint32_t, 1000>>("std::array<uint32_t, 1000>");

    table = new QTableWidget(this);
    table->setColumnCount(20 + 1);
    table->setRowCount(0); // 33
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    table->verticalHeader()->setVisible(true);
    table->horizontalHeader()->setVisible(true);
    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::ExtendedSelection);
    // table->hideColumn(0);
    table->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
    table->resizeColumnsToContents();
    table->resizeRowsToContents();

    // for (size_t r = 0; r < 33; r++)
    //     for (size_t c = 0; c < 20 + 1; c++)
    //         table->setItem(r, c, new QTableWidgetItem("0"));

    QStringList hhl;
    for (size_t i = 1; i <= 20; i++)
        hhl << QString::number(i);
    hhl << QString("(0)");
    table->setHorizontalHeaderLabels(hhl);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(table, 0, 0, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    cornerButton = table->findChild<QAbstractButton *>();
    if (cornerButton)
    {
        cornerButton->disconnect();
        connect(cornerButton, &QAbstractButton::clicked,
                this, &SpawnCountPage::GetSpawnList);
    }
}

void SpawnCountPage::TranslateUI()
{
    setWindowTitle(tr("Spawning Counting"));
}

void SpawnCountPage::UpdateSpawnCount(std::array<uint32_t, 1000> zombies_list)
{
    if (!this->isVisible())
        return;

    uint32_t data[33][20 + 1];
    uint32_t total;
    for (size_t r = 0; r < 33; r++)
        for (size_t c = 0; c < 20 + 1; c++)
            data[r][c] = 0;
    total = 0;

    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 50; j++)
        {
            if (zombies_list[i * 50 + j] > 32 || zombies_list[i * 50 + j] < 0)
                continue;
            data[zombies_list[i * 50 + j]][i] += 1;
            data[zombies_list[i * 50 + j]][20 + 1 - 1] += 1;
            total += 1;
        }
    }

    table->clearContents();
    table->setColumnCount(20 + 1);
    table->setRowCount(33);

    auto min = [](unsigned int a, unsigned int b) -> unsigned int {
        return a < b ? a : b;
    };

    for (size_t r = 0; r < 33; r++)
    {
        for (size_t c = 0; c < 20 + 1; c++)
        {
            unsigned int value = data[r][c];
            QColor color;
            int f = 0;
            if (c == (20 + 1 - 1))
            {
                f = min(value, 300u) * 255 / 500;
                color = QColor(255 - f, 255 - f, 255 - f);
            }
            else if (c == (10 - 1) || c == (20 - 1))
            {
                f = min(value, 20u) * 250 / 30;
                color = QColor(250 - f, 240, 250 - f);
            }
            else
            {
                f = min(value, 20u) * 255 / 30;
                color = QColor(255 - f, 255, 255 - f);
            }
            table->setItem(r, c, new QTableWidgetItem(QString::number(value)));
            table->item(r, c)->setBackground(color);
        }
    }

    QStringList hhl;
    for (size_t i = 1; i <= 20; i++)
        hhl << QString::number(i);
    hhl << (QString("(") + QString::number(total) + QString(")"));
    table->setHorizontalHeaderLabels(hhl);

    QStringList vhl;
    for (size_t i = 0; i < 33; i++)
        vhl << (QString("[") + QString::number(i) + "]" + " " + List::Get().zombieList[i]);
    table->setVerticalHeaderLabels(vhl);

    cornerButton->setText(QString("↻")); // TODO

    for (size_t r = 32; r > 0; r--) // r>=0
    {
        if (data[r][20 + 1 - 1] == 0)
            table->removeRow(r);
    }

    table->resizeColumnsToContents();
    table->resizeRowsToContents();
}

// Target Map

TargetMapPage::TargetMapPage(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<std::array<int, 54>>("std::array<int, 54>");

    for (size_t r = 0; r < 6; r++)
        for (size_t c = 0; c < 9; c++)
            comboBoxes[9 * r + c] = new QComboBox(this);

    seeingStarsRadioButton = new QRadioButton(this);
    artChallengeWallnutRadioButton = new QRadioButton(this);
    artChallengeSunflowerRadioButton = new QRadioButton(this);

    loadButton = new QPushButton(this);
    clearButton = new QPushButton(this);
    setButton = new QPushButton(this);

    seeingStarsRadioButton->setChecked(true);

    mainLayout = new QGridLayout(this);
    for (size_t r = 0; r < 6; r++)
        for (size_t c = 0; c < 9; c++)
            mainLayout->addWidget(comboBoxes[9 * r + c], r, c, 1, 1);
    mainLayout->addWidget(seeingStarsRadioButton, 7, 0, 1, 2);
    mainLayout->addWidget(artChallengeWallnutRadioButton, 7, 2, 1, 2);
    mainLayout->addWidget(artChallengeSunflowerRadioButton, 7, 4, 1, 2);
    mainLayout->addWidget(loadButton, 7, 6, 1, 1);
    mainLayout->addWidget(clearButton, 7, 7, 1, 1);
    mainLayout->addWidget(setButton, 7, 8, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(loadButton, &QPushButton::clicked,
            this, [=]() {
                if (seeingStarsRadioButton->isChecked())
                    emit GetTargetMap(22);
                if (artChallengeWallnutRadioButton->isChecked())
                    emit GetTargetMap(36);
                if (artChallengeSunflowerRadioButton->isChecked())
                    emit GetTargetMap(40);
            });

    connect(clearButton, &QPushButton::clicked,
            this, [=]() {
                for (size_t r = 0; r < 6; r++)
                    for (size_t c = 0; c < 9; c++)
                        comboBoxes[9 * r + c]->setCurrentIndex(0);
            });

    connect(setButton, &QPushButton::clicked,
            this, [=]() {
                std::array<int, 54> map;
                for (size_t r = 0; r < 6; r++)
                    for (size_t c = 0; c < 9; c++)
                        map[9 * r + c] = comboBoxes[9 * r + c]->currentIndex() - 1;
                if (seeingStarsRadioButton->isChecked())
                    emit SetTargetMap(22, map);
                if (artChallengeWallnutRadioButton->isChecked())
                    emit SetTargetMap(36, map);
                if (artChallengeSunflowerRadioButton->isChecked())
                    emit SetTargetMap(40, map);
            });
}

void TargetMapPage::TranslateUI()
{
    for (size_t r = 0; r < 6; r++)
    {
        for (size_t c = 0; c < 9; c++)
        {
            if (comboBoxes[9 * r + c]->count() == 0)
            {
                comboBoxes[9 * r + c]->addItem(tr("Empty"));
                for (size_t i = 0; i < 48; i++)
                    comboBoxes[9 * r + c]->addItem(List::Get().seedList[i]);
            }
            else
            {
                comboBoxes[9 * r + c]->setItemText(0, tr("Empty"));
                for (size_t i = 0; i < 48; i++)
                    comboBoxes[9 * r + c]->setItemText(i + 1, List::Get().seedList[i]);
            }
        }
    }

    seeingStarsRadioButton->setText(List::Get().miniGamesList[22 - 16]);           // Seeing Stars
    artChallengeWallnutRadioButton->setText(List::Get().miniGamesList[36 - 16]);   // Art Challenge Wall-nut
    artChallengeSunflowerRadioButton->setText(List::Get().miniGamesList[40 - 16]); // Art Challenge Sunflower

    loadButton->setText(tr("Load"));
    clearButton->setText(tr("Clear"));
    setButton->setText(tr("Set"));

    setWindowTitle(List::Get().miniGamesList[22 - 16]           //
                   + " / " + List::Get().miniGamesList[36 - 16] //
                   + " / " + List::Get().miniGamesList[40 - 16] //
                   + " " + tr("Target Map Modify"));
}

void TargetMapPage::ShowTargetMap(std::array<int, 54> map)
{
    for (size_t r = 0; r < 6; r++)
        for (size_t c = 0; c < 9; c++)
            comboBoxes[9 * r + c]->setCurrentIndex(map[9 * r + c] + 1);
}

// Cannon Launcher

CannonLauncherPage::CannonLauncherPage(QWidget *parent)
    : QWidget(parent)
{
    indexLabel = new QLabel(this);
    indexSpinBox = new QSpinBox(this);
    indexSpinBox->setRange(0, 1023);
    indexSpinBox->setSingleStep(1);
    indexSpinBox->setValue(0);
    infoLabel = new QLabel(this);

    gridLabel = new QLabel(this);
    rowLabel = new QLabel(this);
    colLabel = new QLabel(this);

    rowSpinBox = new QDoubleSpinBox(this);
    rowSpinBox->setRange(0.0, 7.0);
    rowSpinBox->setSingleStep(1);
    rowSpinBox->setValue(2.00);
    colSpinBox = new QDoubleSpinBox(this);
    colSpinBox->setRange(0.0, 10.0);
    colSpinBox->setSingleStep(1);
    colSpinBox->setValue(9.00);

    coordLabel = new QLabel(this);
    xLabel = new QLabel(this);
    yLabel = new QLabel(this);
    xValueLabel = new QLabel(this);
    yValueLabel = new QLabel(this);

    randomFallCheckBox = new QCheckBox(this);
    launchAllButton = new QPushButton(this);
    launchButton = new QPushButton(this);

    launchButton->setEnabled(false);

    xLabel->setText("X");
    yLabel->setText("Y");
    xValueLabel->setText("");
    yValueLabel->setText("");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(indexLabel, 0, 0, 1, 1);
    mainLayout->addWidget(indexSpinBox, 0, 1, 1, 1);
    mainLayout->addWidget(infoLabel, 0, 2, 1, 3);
    mainLayout->addWidget(gridLabel, 2, 0, 1, 1);
    mainLayout->addWidget(rowLabel, 2, 1, 1, 1);
    mainLayout->addWidget(rowSpinBox, 2, 2, 1, 1);
    mainLayout->addWidget(colLabel, 2, 3, 1, 1);
    mainLayout->addWidget(colSpinBox, 2, 4, 1, 1);
    mainLayout->addWidget(coordLabel, 3, 0, 1, 1);
    mainLayout->addWidget(xLabel, 3, 1, 1, 1);
    mainLayout->addWidget(xValueLabel, 3, 2, 1, 1);
    mainLayout->addWidget(yLabel, 3, 3, 1, 1);
    mainLayout->addWidget(yValueLabel, 3, 4, 1, 1);
    mainLayout->addWidget(randomFallCheckBox, 4, 0, 1, 1);
    mainLayout->addWidget(launchAllButton, 4, 1, 1, 2);
    mainLayout->addWidget(launchButton, 4, 3, 1, 2);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(indexSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &CannonLauncherPage::GetCobInfo);

    connect(indexSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
            this, &CannonLauncherPage::GetScene);

    connect(rowSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &CannonLauncherPage::GetScene);

    connect(colSpinBox, static_cast<void (QDoubleSpinBox::*)(double)>(&QDoubleSpinBox::valueChanged),
            this, &CannonLauncherPage::GetScene);

    connect(launchButton, &QPushButton::clicked,
            this, [=]() {
                int index = indexSpinBox->value();
                int x = xValueLabel->text().toInt();
                int y = yValueLabel->text().toInt();
                emit LaunchCannon(index, x, y);
            });

    connect(launchAllButton, &QPushButton::clicked,
            this, [=]() {
                bool random_fall = randomFallCheckBox->isChecked();
                int x = xValueLabel->text().toInt();
                int y = yValueLabel->text().toInt();
                emit LaunchAllCannon(random_fall, x, y);
            });
}

void CannonLauncherPage::TranslateUI()
{
    indexLabel->setText(tr("Index"));
    infoLabel->setText(tr("Not Found"));

    gridLabel->setText(tr("Grid"));
    rowLabel->setText(tr("Row"));
    colLabel->setText(tr("Column"));

    coordLabel->setText(tr("Coordinate"));
    randomFallCheckBox->setText(tr("Random Fall"));
    launchAllButton->setText(tr("Launch All"));
    launchButton->setText(tr("Launch"));

    setWindowTitle(tr("Cannon Launcher"));
}

void CannonLauncherPage::ShowCobInfo(bool is_cob_cannon, int row, int col)
{
    if (is_cob_cannon)
    {
        QString text = QString(tr("Cob Cannon")) + " " + tr("in")             //
                       + " " + QString::number(row + 1) + " " + tr("Row")     //
                       + " " + QString::number(col + 1) + " " + tr("Column"); //
        infoLabel->setText(text);
        launchButton->setEnabled(true);
    }
    else
    {
        infoLabel->setText(tr("Not Found"));
        launchButton->setEnabled(false);
    }
}

void CannonLauncherPage::CalculateCoord(int scene)
{
    if (scene == -1)
    {
        xValueLabel->setText("0");
        yValueLabel->setText("0");
        return;
    }

    double row = rowSpinBox->value();
    double col = colSpinBox->value();
    int x, y;

    x = 80 * col;
    if (scene == 2 || scene == 3)
        y = 55 + 85 * row;
    else if (scene == 4 || scene == 5)
        if (col >= 6.0)
            y = 45 + 85 * row;
        else
            y = 45 + 85 * row + 20 * (6 - col);
    else
        y = 40 + 100 * row;

    xValueLabel->setText(QString::number(x));
    yValueLabel->setText(QString::number(y));
}

// Portal

PortalPage::PortalPage(QWidget *parent)
    : QWidget(parent)
{
    label_black_row = new QLabel(this);
    label_black_col = new QLabel(this);
    label_white_row = new QLabel(this);
    label_white_col = new QLabel(this);
    label_black_1 = new QLabel(this);
    label_black_2 = new QLabel(this);
    label_white_1 = new QLabel(this);
    label_white_2 = new QLabel(this);

    label_black_1->setAlignment(Qt::AlignCenter);
    label_black_2->setAlignment(Qt::AlignCenter);
    label_white_1->setAlignment(Qt::AlignCenter);
    label_white_2->setAlignment(Qt::AlignCenter);

    line_edit_black_1_row = new QLineEdit(this);
    line_edit_black_1_row->setValidator(new QIntValidator(1, 6, this));
    line_edit_black_1_col = new QLineEdit(this);
    line_edit_black_1_col->setValidator(new QIntValidator(1, 10, this));
    line_edit_black_2_row = new QLineEdit(this);
    line_edit_black_2_row->setValidator(new QIntValidator(1, 6, this));
    line_edit_black_2_col = new QLineEdit(this);
    line_edit_black_2_col->setValidator(new QIntValidator(1, 10, this));
    line_edit_white_1_row = new QLineEdit(this);
    line_edit_white_1_row->setValidator(new QIntValidator(1, 6, this));
    line_edit_white_1_col = new QLineEdit(this);
    line_edit_white_1_col->setValidator(new QIntValidator(1, 10, this));
    line_edit_white_2_row = new QLineEdit(this);
    line_edit_white_2_row->setValidator(new QIntValidator(1, 6, this));
    line_edit_white_2_col = new QLineEdit(this);
    line_edit_white_2_col->setValidator(new QIntValidator(1, 10, this));

    check_box_portal_start = new QCheckBox(this);
    check_box_portal_lock = new QCheckBox(this);
    push_button_portal_set = new QPushButton(this);

    line_edit_black_1_row->setText("1");
    line_edit_black_1_col->setText("6");
    line_edit_black_2_row->setText("2");
    line_edit_black_2_col->setText("7");
    line_edit_white_1_row->setText("3");
    line_edit_white_1_col->setText("8");
    line_edit_white_2_row->setText("4");
    line_edit_white_2_col->setText("9");

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(label_black_row, 4, 2, 1, 1);
    mainLayout->addWidget(label_black_col, 4, 3, 1, 1);
    mainLayout->addWidget(label_white_row, 4, 6, 1, 1);
    mainLayout->addWidget(label_white_col, 4, 7, 1, 1);
    mainLayout->addWidget(label_black_1, 5, 0, 1, 2);
    mainLayout->addWidget(label_black_2, 6, 0, 1, 2);
    mainLayout->addWidget(label_white_1, 5, 4, 1, 2);
    mainLayout->addWidget(label_white_2, 6, 4, 1, 2);
    mainLayout->addWidget(line_edit_black_1_row, 5, 2, 1, 1);
    mainLayout->addWidget(line_edit_black_1_col, 5, 3, 1, 1);
    mainLayout->addWidget(line_edit_black_2_row, 6, 2, 1, 1);
    mainLayout->addWidget(line_edit_black_2_col, 6, 3, 1, 1);
    mainLayout->addWidget(line_edit_white_1_row, 5, 6, 1, 1);
    mainLayout->addWidget(line_edit_white_1_col, 5, 7, 1, 1);
    mainLayout->addWidget(line_edit_white_2_row, 6, 6, 1, 1);
    mainLayout->addWidget(line_edit_white_2_col, 6, 7, 1, 1);
    mainLayout->addWidget(check_box_portal_start, 4, 9, 1, 2);
    mainLayout->addWidget(check_box_portal_lock, 5, 9, 1, 2);
    mainLayout->addWidget(push_button_portal_set, 6, 9, 1, 4);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(check_box_portal_start, &QCheckBox::stateChanged,
            this, [=]() {
                emit StartPortal(check_box_portal_start->isChecked());
            });

    connect(check_box_portal_lock, &QCheckBox::stateChanged,
            this, [=]() {
                emit LockPortal(check_box_portal_lock->isChecked());
            });

    connect(push_button_portal_set, &QPushButton::clicked,
            this, [=]() {
                if (check_box_portal_start->checkState() == Qt::Checked)
                {
                    int b1r = line_edit_black_1_row->text().toInt() - 1;
                    int b1c = line_edit_black_1_col->text().toInt() - 1;
                    int b2r = line_edit_black_2_row->text().toInt() - 1;
                    int b2c = line_edit_black_2_col->text().toInt() - 1;
                    int w1r = line_edit_white_1_row->text().toInt() - 1;
                    int w1c = line_edit_white_1_col->text().toInt() - 1;
                    int w2r = line_edit_white_2_row->text().toInt() - 1;
                    int w2c = line_edit_white_2_col->text().toInt() - 1;
                    emit SetPortal(b1r, b1c, b2r, b2c, w1r, w1c, w2r, w2c);
                }
            });
}

void PortalPage::TranslateUI()
{
    label_black_row->setText(tr("Row"));
    label_black_col->setText(tr("Column"));
    label_white_row->setText(tr("Row"));
    label_white_col->setText(tr("Column"));
    label_black_1->setText(tr("Black1"));
    label_black_2->setText(tr("Black2"));
    label_white_1->setText(tr("White1"));
    label_white_2->setText(tr("White2"));

    check_box_portal_start->setText(tr("Start"));
    check_box_portal_lock->setText(tr("Lock"));
    push_button_portal_set->setText(tr("Set Portal"));

    setWindowTitle(tr("Portal"));
}

// I, Zombie Endless

IzeLineupPage::IzeLineupPage(QWidget *parent)
    : QWidget(parent)
{
    qRegisterMetaType<std::array<int, 25>>("std::array<int, 25>");

    int tmp[22] = {
        0,  // 豌豆射手
        1,  // 向日葵
        3,  // 坚果
        4,  // 土豆地雷
        5,  // 寒冰射手
        6,  // 大嘴花
        7,  // 双重射手
        8,  // 小喷菇
        10, // 大喷菇
        13, // 胆小菇
        17, // 倭瓜
        18, // 三重射手
        21, // 地刺
        22, // 火炬树桩
        23, // 高坚果
        26, // 仙人掌
        28, // 裂荚射手
        29, // 杨桃
        31, // 磁力菇
        34, // 玉米投手
        36, // 大蒜
        37, // 叶子伞
    };
    memcpy(izPlantTypes, tmp, sizeof(tmp));

    for (size_t r = 0; r < 5; r++)
        for (size_t c = 0; c < 5; c++)
            comboBoxes[5 * r + c] = new QComboBox(this);

    loadButton = new QPushButton(this);
    clearButton = new QPushButton(this);
    setButton = new QPushButton(this);

    mainLayout = new QGridLayout(this);
    for (size_t r = 0; r < 5; r++)
        for (size_t c = 0; c < 5; c++)
            mainLayout->addWidget(comboBoxes[5 * r + c], r, c, 1, 1);
    mainLayout->addWidget(loadButton, 5, 0, 1, 1);
    mainLayout->addWidget(clearButton, 5, 1, 1, 1);
    mainLayout->addWidget(setButton, 5, 4, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);

    connect(loadButton, &QPushButton::clicked,
            this, &IzeLineupPage::GetIzeLineup);

    connect(clearButton, &QPushButton::clicked,
            this, [=]() {
                for (size_t r = 0; r < 5; r++)
                    for (size_t c = 0; c < 5; c++)
                        comboBoxes[5 * r + c]->setCurrentIndex(0);
            });

    connect(setButton, &QPushButton::clicked,
            this, [=]() {
                std::array<int, 25> iz_l;
                for (size_t r = 0; r < 5; r++)
                {
                    for (size_t c = 0; c < 5; c++)
                    {
                        int index = comboBoxes[5 * r + c]->currentIndex();
                        if (index == 0)
                            iz_l[5 * r + c] = -1;
                        else
                            iz_l[5 * r + c] = izPlantTypes[index - 1];
                    }
                }
                emit SetIzeLineup(iz_l);
            });
}

void IzeLineupPage::TranslateUI()
{
    for (size_t r = 0; r < 5; r++)
    {
        for (size_t c = 0; c < 5; c++)
        {
            if (comboBoxes[5 * r + c]->count() == 0)
            {
                comboBoxes[5 * r + c]->addItem(tr("Empty"));
                for (size_t i = 0; i < 22; i++)
                    comboBoxes[5 * r + c]->addItem(List::Get().seedList[izPlantTypes[i]]);
            }
            else
            {
                comboBoxes[5 * r + c]->setItemText(0, tr("Empty"));
                for (size_t i = 0; i < 22; i++)
                    comboBoxes[5 * r + c]->setItemText(i + 1, List::Get().seedList[izPlantTypes[i]]);
            }
        }
    }

    loadButton->setText(tr("Load"));
    clearButton->setText(tr("Clear"));
    setButton->setText(tr("Set"));

    setWindowTitle(tr("I, Zombie Endless Lineup"));
}

void IzeLineupPage::ShowIzeLineup(std::array<int, 25> iz_l)
{
    for (size_t r = 0; r < 5; r++)
    {
        for (size_t c = 0; c < 5; c++)
        {
            int plant_type = iz_l[5 * r + c];

            bool found = false;
            int index = 0;
            for (size_t i = 0; i < 22; i++)
            {
                if (izPlantTypes[i] == plant_type)
                {
                    found = true;
                    index = i;
                    break;
                }
            }

            if (found)
                comboBoxes[5 * r + c]->setCurrentIndex(index + 1);
            else
                comboBoxes[5 * r + c]->setCurrentIndex(0);
        }
    }
}

// Document

DocumentPage::DocumentPage(QWidget *parent)
    : QWidget(parent)
{
    document = new QTextBrowser(this);
    document->setOpenExternalLinks(true);

    mainLayout = new QGridLayout(this);
    mainLayout->addWidget(document, 0, 0, 1, 1);

    for (int i = 0; i < mainLayout->rowCount(); i++)
        mainLayout->setRowStretch(i, 1);
    for (int i = 0; i < mainLayout->columnCount(); i++)
        mainLayout->setColumnStretch(i, 1);
}

void DocumentPage::TranslateUI()
{
    document->setText(tr("<style>a {text-decoration: none; color: blue}</style>"
                         "<h2>About</h2>"
                         "<p>This software (PvZ Tools) is applicable to Plants vs. Zombies 1.0.0.1051 original English version only (which you can <a href=\"https://pvz.lmintlcx.com/download/\">download here</a>).</p>"
                         "<p>Excessive modification or forced use of non-corresponding game versions can easily cause the game to crash, please back up data file before use. All effects caused by using this software are responsibility of user himself.</p>"
                         "<p>Some behavior of trainer (finding game progress, modifying memory data, remote injection code, etc.) may be considered dangerous by anti-virus software. Please decide whether to trust this software yourself.</p>"
                         "<p>Reasonable uses of trainer include, but not limited to, demonstrations, testing, research, and entertainment. Abuse of modifiers may reduce the fun of game seriously, please use it with caution, especially newbies.</p>"
                         "<p>There may be some bugs with this software, users can summit feedback or feature request to the author. The beta version of this software has a time limit, please download latest version if it prompt expires.</p>"
                         "<p>Configuration information is saved in \"HKEY_CURRENT_USER\\SOFTWARE\\Cube Studio\\PvZ Tools\\v2\". You can export this registry item for back up, or clean it after delete this software.</p>"
                         "<p>Most important data (memory address) comes from existing public information and other open source modifiers. And source code is copy and paste from Stack Overflow.</p>"
                         "<p>All source code is located at <a href=\"https://github.com/lmintlcx/pvztools/\">https://github.com/lmintlcx/pvztools/</a>.</p>"
                         "<h2>Spawn</h2>"
                         "<p>This feature is suitable for later period of survival endless. Size of zombie's spawning list is 1000, which is 20 waves per level and 50 zombies per wave.</p>"
                         "<p>The spawn page has two modes: \"brief\" and \"detailed\".</p>"
                         "<p>When switching between different pages, if the number of zombie types selected on target page is 0, selected zombie types on current page will be synchronized to target page (not one-to-one correspondence).</p>"
                         "<p>In brief mode, you can switch layout of the option boxes, in order of zombies in almanac or in same position as the PVZombiesSeed.exe.</p>"
                         "<p>In brief mode, Conehead Zombie and Newspaper Zombie are mutually exclusive if \"Limit Spawn Count\" is checked, and it will limit the number of selected zombie types, up to 10 types except Bungee Zombie and Zombie Yeti. (Note that this limitation is not same as the game itself.)</p>"
                         "<p>The difference between different spawn mode:<br>Natural spawn changes the zombie types only and calls built-in function of game to generates zombies list.<br>Extreme spawn is to evenly populate the zombies list with seleted zombie types.<br>Simulate natural spawn is randomly fill the zombies list with seleted zombie types according to certern ratio, meanwhile decrease the probability of GigaGargantuar in non flag wave.</p>"
                         "<p>Special deal with some zombies:<br>When limit Flag Zombie, Flag Zombie will only appear in each flag wave (huge wave).<br>When limit Zombie Yeti, there will be only one Zombie Yeti.<br>When limit Bungee Zombie, Bungee Zombie will only appear in flag wave (huge wave).<br>When limit GigaGargantuar, GigaGargantuar will only appear in selected wave(s) (20 waves total).</p>"
                         "<p>When using natural spawn in brief mode, there must be Zombie.</p>"
                         "<p>When using extreme spawn in brief mode, there must be Zombie and Flag Zombie. Flag Zombie, Zombie Yeti and Bungee Zombie is limited, and GigaGargantuar has no limit.</p>"
                         "<p>When using simulate natural spawn in detailed mode, there must be Zombie and Flag Zombie. Flag Zombie, Zombie Yeti and Bungee Zombie is limited.</p>"
                         "<h2>Lineup</h2>"
                         "<p>Checking \"Quick Lineup Mode\" will enable these features: Auto Collect, Cob Cannon No CD, Plant Invincible, Stop Spawning, Ignore Sun, Slots No CD, Purple Seed Unlimited, No Fog.</p>"
                         "<p>Clicking \"Quick Pass\" will end current level directly, kill all zombies on the field, set the number of sunshine to 8000, and set the number of levels to 1009 (2020 flags completed). You can modify sunshine and level in corresponding page by pause the game immediately after clicking it.</p>"
                         "<p>Format of lineup string is compatible with <a href=\"https://pvz.lmintlcx.com/lineup/\">Array Design</a>.</p>"
                         "<p>The built-in lineup string includes some well-known build in <a href=\"https://tieba.baidu.com/f?kw=植物大战僵尸&ie=utf-8&tab=good\">good tab</a> at Baidu Tieba. Players can adjust lineup as needed, don't have to follow the original array completely.</p>"
                         "<p>Clicking \"Update\" will update built-in array list via Internet. Which is collected by me and will be update if I'm happy.</p>"
                         "<p>Modifying game scene may cause some unknown problems, therefore the \"Allow Switch Scene\" option is not checked by default. It is recommended to enter the hidden scene in a <a href=\"https://pvz.lmintlcx.com/pvztoolsdemo/hiddenscene/\">more conventional way</a> and then mix to \"Survival Endless\" mode.</p>"
                         "<p>When \"Keep HP Status\" is checked, appearance status of some plants (Wall-nut, Tall-nut, Pumpkin, Garlic, Spikerock) will be preserved when importing or exporting lineup strings.</p>"
                         "<h2>Others</h2>"
                         "<p>The \"Open Data Dir\" feature is temporarily unavailable on XP systems (the data file is located in the \"userdata\" folder in game directory). For Vista and above, it's located in \"C:\\ProgramData\\PopCap Games\\PlantsVsZombies\\userdata\\\" folder.</p>"
                         "<p>The unpacked file is located in the specified folder. But the packaged file will be named with \"main_&lt;number&gt;.pak\", please rename it to \"main.pak\" and replace the original game file (remember to backup first).</p>"));

    setWindowTitle(tr("Document"));
}

// <style>a {text-decoration: none; color: blue}</style>
// <h2>关于</h2>
// <p>本软件（PvZ Tools）仅适用于植物大战僵尸 1.0.0.1051 英文原版（可从 <a href="https://pvz.lmintlcx.com/download/">这里下载</a>）。</p>
// <p>过度修改或者强行使用不对应的游戏版本很容易造成游戏崩溃，使用前请及时备份存档。对于使用本软件造成的所有影响由用户自己负责。</p>
// <p>修改器的部分行为（查找游戏进程，修改内存数据，远程注入代码等）可能会被杀毒软件视为危险行为，请自行决定是否信任本软件。</p>
// <p>修改器的合理用途包括但不限于演示、测试、研究和娱乐。滥用修改器会严重降低游戏乐趣，新手请慎重使用。</p>
// <p>本软件可能存在一些问题，用户可以向作者提供问题反馈或者功能需求。测试版有使用期限限制，如果提示过期请下载最新版本。</p>
// <p>配置信息保存在“HKEY_CURRENT_USER\SOFTWARE\Cube Studio\PvZ Tools\v2”。你可以导出这个注册表项目来备份，或者在删除本软件后清理它。</p>
// <p>大部分核心数据（内存基址）来自于已有公开资料和其他开源修改器。而源代码是从栈溢出（Stack Overflow）复制粘贴的。</p>
// <p>所有源代码位于 <a href="https://github.com/lmintlcx/pvztools/">https://github.com/lmintlcx/pvztools/</a> 。</p>
// <h2>出怪</h2>
// <p>此功能适用于无尽后期调节出怪。出怪列表共用到 1000 只僵尸，其中每一次选卡 20 波，每波 50 只。</p>
// <p>出怪页面有两种模式：“简略” 和 “详细”。</p>
// <p>切换不同出怪页面时，如果目标页面所选的僵尸种类数量为 0，则会将当前页面已选的僵尸种类同步到另一页面上（并不是一一对应的）。</p>
// <p>简略模式下可以切换选项框的排列布局，按僵尸在图鉴的顺序或者和小王子出怪修改器一样的位置。</p>
// <p>在简略模式下勾选“限制出怪种类数”后路障和读报互斥，并且限制能够选择的出怪种类数量为除蹦极和雪人外最多 10 种。（注意这个限制和游戏本身的出怪情况并不相同）。</p>
// <p>不同出怪模式的区别：<br>自然出怪只改变出怪种类，再由游戏内置的函数生成出怪列表。<br>极限出怪是把所选僵尸种类按顺序均匀地填充到出怪列表。<br>模拟自然出怪则是按一定的比例随机填充出怪列表，在非旗帜波会降低红眼的出现概率。</p>
// <p>一些僵尸的特殊处理：<br>限制旗帜后，旗帜只在每个旗帜波（大波）出现一只。<br>限制雪人后，雪人只出现一只。<br>限制蹦极后，蹦极只在旗帜波（大波）出现。<br>限制红眼后，红眼只在所选的波次出现（总共 20 波）。</p>
// <p>简略模式下使用自然出怪，普僵必出。</p>
// <p>简略模式下使用极限出怪，普僵旗帜必出，限制旗帜雪人蹦极，不限制红眼。</p>
// <p>详细模式下使用模拟自然出怪，普僵旗帜必出，限制旗帜雪人蹦极。</p>
// <h2>布阵</h2>
// <p>勾选“快捷布阵模式”会开启这些功能：自动收集、玉米炮无冷却、植物无敌、暂停出怪、无视阳光、卡片无冷却、紫卡无限制、浓雾透视。</p>
// <p>点击“快速过关”后会直接结束本关卡，秒杀所有场上僵尸，并将阳光数设置为 8000，关卡数设置为 1009（已完成 2020 面旗帜数）。可以在点击后立即暂停游戏并去对应的页面修改阳光和关卡数。</p>
// <p>布阵字符串格式和 <a href="https://pvz.lmintlcx.com/lineup/">网页布阵器</a> 互通。</p>
// <p>内置布阵字符串包括一些贴吧 <a href="https://tieba.baidu.com/f?kw=植物大战僵尸&ie=utf-8&tab=good">精品区</a> 知名阵型。玩家可根据需要调整阵型，不需要完全遵循原阵。</p>
// <p>点击“更新”后会联网更新内置的阵型列表。个人整理，随缘更新。</p>
// <p>修改游戏场地可能会造成一些不为人知的问题，因此“允许切换场景”选项默认不勾选。建议用 <a href="https://pvz.lmintlcx.com/pvztoolsdemo/hiddenscene/">更加常规的方法</a> 进入隐藏场地再混乱到“生存无尽”模式。</p>
// <p>勾选“保持血量状态”后，导入或导出字符串时部分植物（坚果、高坚果、南瓜头、大蒜、地刺王）的残血状态会得到保留。</p>
// <h2>其他</h2>
// <p>“打开存档目录”功能在 XP 系统上暂时不可用（存档文件位于游戏目录内的“userdata”文件夹）。对于 Vista 以及更高版本的系统，存档文件位于“C:\ProgramData\PopCap Games\PlantsVsZombies\userdata\”文件夹。</p>
// <p>解包文件位于指定的文件夹内。而打包文件会以“main_&lt;数字&gt;.pak”的格式命名，请将其改名为“main.pak”并且替换掉原来的游戏文件（记得先备份）。</p>

} // namespace Pt
