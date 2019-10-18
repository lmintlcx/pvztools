/*
 * @Author: lmintlcx 
 * @Date: 2018-07-01 21:58:32 
 * @Description: Strings.
 */

#pragma once

#include <QObject>
#include <QStringList>

namespace Pt
{

class List : public QObject
{
  Q_OBJECT

private:
  List();
  ~List();

public:
  static List &Get();
  void Init();

public:
  QStringList pageList;
  QStringList izeArrayList;
  QStringList adventureList;
  QStringList miniGamesList;
  QStringList puzzleList;
  QStringList survivalList;
  QStringList damageList;
  QStringList hpList;
  QStringList coinList;
  QStringList timeList;
  QStringList blockTypeList;
  QStringList rowTypeList;
  QStringList sceneList;
  QStringList musicList;
  QStringList itemList;
  QStringList zombieStatusList;
  QStringList zombieList;
  QStringList slotsIndexList;
  QStringList seedList;
  QStringList rowList;
  QStringList gardenHeadersList;
  QStringList gardenSceneList;
  QStringList directionList;
  QStringList colorList;
  QStringList plantStatusList;
  QStringList vaseHeadersList;
  QStringList vaseSkinList;
  QStringList vaseTypeList;
  QStringList debugModeList;
};

} // namespace Pt
