<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>Pt::CannonLauncherPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5422"/>
        <source>Index</source>
        <translation>序号</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5423"/>
        <location filename="../src/pages.cpp" line="5449"/>
        <source>Not Found</source>
        <translation>未找到</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5425"/>
        <source>Grid</source>
        <translation>格子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5426"/>
        <location filename="../src/pages.cpp" line="5442"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5427"/>
        <location filename="../src/pages.cpp" line="5443"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5429"/>
        <source>Coordinate</source>
        <translation>坐标</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5430"/>
        <source>Random Fall</source>
        <translation>随机落点</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5431"/>
        <source>Launch All</source>
        <translation>发射全部</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5432"/>
        <source>Launch</source>
        <translation>发射</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5434"/>
        <source>Cannon Launcher</source>
        <translation>加农炮发射器</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5441"/>
        <source>Cob Cannon</source>
        <translation>玉米加农炮</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5441"/>
        <source>in</source>
        <translation>位于</translation>
    </message>
</context>
<context>
    <name>Pt::DocumentPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5764"/>
        <source>&lt;style&gt;a {text-decoration: none; color: blue}&lt;/style&gt;&lt;h2&gt;About&lt;/h2&gt;&lt;p&gt;This software (PvZ Tools) is applicable to Plants vs. Zombies 1.0.0.1051 original English version only (which you can &lt;a href=&quot;https://pvz.lmintlcx.com/download/&quot;&gt;download here&lt;/a&gt;).&lt;/p&gt;&lt;p&gt;Excessive modification or forced use of non-corresponding game versions can easily cause the game to crash, please back up data file before use. All effects caused by using this software are responsibility of user himself.&lt;/p&gt;&lt;p&gt;Some behavior of trainer (finding game progress, modifying memory data, remote injection code, etc.) may be considered dangerous by anti-virus software. Please decide whether to trust this software yourself.&lt;/p&gt;&lt;p&gt;Reasonable uses of trainer include, but not limited to, demonstrations, testing, research, and entertainment. Abuse of modifiers may reduce the fun of game seriously, please use it with caution, especially newbies.&lt;/p&gt;&lt;p&gt;There may be some bugs with this software, users can summit feedback or feature request to the author. The beta version of this software has a time limit, please download latest version if it prompt expires.&lt;/p&gt;&lt;p&gt;Configuration information is saved in &quot;HKEY_CURRENT_USER\SOFTWARE\Cube Studio\PvZ Tools\v2&quot;, you can export this registry item for back up, or clean it after delete this software.&lt;br&gt;(Starting from version 2.5.0, these configurations are in the &quot;pvztools.ini&quot; file which located at the same directory as the main program.)&lt;/p&gt;&lt;p&gt;Most important data (memory address) comes from existing public information and other open source modifiers. And source code is copy and paste from Stack Overflow.&lt;/p&gt;&lt;p&gt;All source code is located at &lt;a href=&quot;https://github.com/lmintlcx/pvztools/&quot;&gt;https://github.com/lmintlcx/pvztools/&lt;/a&gt;.&lt;/p&gt;&lt;h2&gt;Spawn&lt;/h2&gt;&lt;p&gt;This feature is suitable for later period of survival endless. Size of zombie&apos;s spawning list is 1000, which is 20 waves per level and 50 zombies per wave.&lt;/p&gt;&lt;p&gt;The spawn page has two modes: &quot;brief&quot; and &quot;detailed&quot;.&lt;/p&gt;&lt;p&gt;When switching between different pages, if the number of zombie types selected on target page is 0, selected zombie types on current page will be synchronized to target page (not one-to-one correspondence).&lt;/p&gt;&lt;p&gt;In brief mode, you can switch layout of the option boxes, in order of zombies in almanac or in same position as the PVZombiesSeed.exe.&lt;/p&gt;&lt;p&gt;In brief mode, Conehead Zombie and Newspaper Zombie are mutually exclusive if &quot;Limit Spawn Count&quot; is checked, and it will limit the number of selected zombie types, up to 10 types except Bungee Zombie and Zombie Yeti. (Note that this limitation is not same as the game itself.)&lt;/p&gt;&lt;p&gt;The difference between different spawn mode:&lt;br&gt;Natural spawn changes the zombie types only and calls built-in function of game to generates zombies list.&lt;br&gt;Extreme spawn is to evenly populate the zombies list with seleted zombie types.&lt;br&gt;Simulate natural spawn is randomly fill the zombies list with seleted zombie types according to certern ratio, meanwhile decrease the probability of GigaGargantuar in non flag wave.&lt;/p&gt;&lt;p&gt;Special deal with some zombies:&lt;br&gt;When limit Flag Zombie, Flag Zombie will only appear in each flag wave (huge wave).&lt;br&gt;When limit Zombie Yeti, there will be only one Zombie Yeti.&lt;br&gt;When limit Bungee Zombie, Bungee Zombie will only appear in flag wave (huge wave).&lt;br&gt;When limit GigaGargantuar, GigaGargantuar will only appear in selected wave(s) (20 waves total).&lt;/p&gt;&lt;p&gt;When using natural spawn in brief mode, there must be Zombie.&lt;/p&gt;&lt;p&gt;When using extreme spawn in brief mode, there must be Zombie and Flag Zombie. Flag Zombie, Zombie Yeti and Bungee Zombie is limited, and GigaGargantuar has no limit.&lt;/p&gt;&lt;p&gt;When using simulate natural spawn in detailed mode, there must be Zombie and Flag Zombie. Flag Zombie, Zombie Yeti and Bungee Zombie is limited.&lt;/p&gt;&lt;h2&gt;Lineup&lt;/h2&gt;&lt;p&gt;Checking &quot;Quick Lineup Mode&quot; will enable these features: Auto Collect, Cob Cannon No CD, Plant Invincible, Stop Spawning, Ignore Sun, Slots No CD, Purple Seed Unlimited, No Fog.&lt;/p&gt;&lt;p&gt;Clicking &quot;Quick Pass&quot; will end current level directly, kill all zombies on the field, set the number of sunshine to 8000, and set the number of levels to 1010 (2022 flags completed). You can modify sunshine and level in corresponding page by pause the game immediately after clicking it.&lt;/p&gt;&lt;p&gt;Format of lineup string is compatible with &lt;a href=&quot;https://pvz.lmintlcx.com/lineup/&quot;&gt;Array Design&lt;/a&gt;.&lt;/p&gt;&lt;p&gt;The built-in lineup string includes some well-known build in &lt;a href=&quot;https://tieba.baidu.com/f?kw=植物大战僵尸&amp;ie=utf-8&amp;tab=good&quot;&gt;good tab&lt;/a&gt; at Baidu Tieba. Players can adjust lineup as needed, don&apos;t have to follow the original array completely.&lt;/p&gt;&lt;p&gt;Clicking &quot;Update&quot; will update built-in array list via Internet. Which is collected by me and will be update if I&apos;m happy.&lt;/p&gt;&lt;p&gt;Modifying game scene may cause some unknown problems, therefore the &quot;Allow Switch Scene&quot; option is not checked by default. It is recommended to enter the hidden scene in a &lt;a href=&quot;https://pvz.lmintlcx.com/pvztoolsdemo/hiddenscene/&quot;&gt;more conventional way&lt;/a&gt; and then mix to &quot;Survival Endless&quot; mode.&lt;/p&gt;&lt;p&gt;When &quot;Keep HP Status&quot; is checked, appearance status of some plants (Wall-nut, Tall-nut, Pumpkin, Garlic, Spikerock) will be preserved when importing or exporting lineup strings.&lt;/p&gt;&lt;h2&gt;Others&lt;/h2&gt;&lt;p&gt;The &quot;Open Data Dir&quot; feature is temporarily unavailable on XP systems (the data file is located in the &quot;userdata&quot; folder in game directory). For Vista and above, it&apos;s located in &quot;C:\ProgramData\PopCap Games\PlantsVsZombies\userdata\&quot; folder.&lt;/p&gt;&lt;p&gt;The unpacked file is located in the specified folder. But the packaged file will be named with &quot;main_&amp;lt;number&amp;gt;.pak&quot;, please rename it to &quot;main.pak&quot; and replace the original game file (remember to backup first).&lt;/p&gt;</source>
        <translation>&lt;style&gt;a {text-decoration: none; color: blue}&lt;/style&gt;
&lt;h2&gt;关于&lt;/h2&gt;
&lt;p&gt;本软件（PvZ Tools）仅适用于植物大战僵尸 1.0.0.1051 英文原版（可从 &lt;a href=&quot;https://pvz.lmintlcx.com/download/&quot;&gt;这里下载&lt;/a&gt;）。&lt;/p&gt;
&lt;p&gt;过度修改或者强行使用不对应的游戏版本很容易造成游戏崩溃，使用前请及时备份存档。对于使用本软件造成的所有影响由用户自己负责。&lt;/p&gt;
&lt;p&gt;修改器的部分行为（查找游戏进程，修改内存数据，远程注入代码等）可能会被杀毒软件视为危险行为，请自行决定是否信任本软件。&lt;/p&gt;
&lt;p&gt;修改器的合理用途包括但不限于演示、测试、研究和娱乐。滥用修改器会严重降低游戏乐趣，新手请慎重使用。&lt;/p&gt;
&lt;p&gt;本软件可能存在一些问题，用户可以向作者提供问题反馈或者功能需求。测试版有使用期限限制，如果提示过期请下载最新版本。&lt;/p&gt;
&lt;p&gt;配置信息保存在“HKEY_CURRENT_USER\SOFTWARE\Cube Studio\PvZ Tools\v2”，你可以导出这个注册表项目来备份，或者在删除本软件后清理它。&lt;br&gt;（从 2.5.0 版本开始，这些配置位于主程序同目录下的 “pvztools.ini” 文件中。）&lt;/p&gt;
&lt;p&gt;大部分核心数据（内存基址）来自于已有公开资料和其他开源修改器。而源代码是从栈溢出（Stack Overflow）复制粘贴的。&lt;/p&gt;
&lt;p&gt;所有源代码位于 &lt;a href=&quot;https://github.com/lmintlcx/pvztools/&quot;&gt;https://github.com/lmintlcx/pvztools/&lt;/a&gt; 。&lt;/p&gt;
&lt;h2&gt;出怪&lt;/h2&gt;
&lt;p&gt;此功能适用于无尽后期调节出怪。出怪列表共用到 1000 只僵尸，其中每一次选卡 20 波，每波 50 只。&lt;/p&gt;
&lt;p&gt;出怪页面有两种模式：“简略” 和 “详细”。&lt;/p&gt;
&lt;p&gt;切换不同出怪页面时，如果目标页面所选的僵尸种类数量为 0，则会将当前页面已选的僵尸种类同步到另一页面上（并不是一一对应的）。&lt;/p&gt;
&lt;p&gt;简略模式下可以切换选项框的排列布局，按僵尸在图鉴的顺序或者和小王子出怪修改器一样的位置。&lt;/p&gt;
&lt;p&gt;在简略模式下勾选“限制出怪种类数”后路障和读报互斥，并且限制能够选择的出怪种类数量为除蹦极和雪人外最多 10 种。（注意这个限制和游戏本身的出怪情况并不相同）。&lt;/p&gt;
&lt;p&gt;不同出怪模式的区别：&lt;br&gt;自然出怪只改变出怪种类，再由游戏内置的函数生成出怪列表。&lt;br&gt;极限出怪是把所选僵尸种类按顺序均匀地填充到出怪列表。&lt;br&gt;模拟自然出怪则是按一定的比例随机填充出怪列表，在非旗帜波会降低红眼的出现概率。&lt;/p&gt;
&lt;p&gt;一些僵尸的特殊处理：&lt;br&gt;限制旗帜后，旗帜只在每个旗帜波（大波）出现一只。&lt;br&gt;限制雪人后，雪人只出现一只。&lt;br&gt;限制蹦极后，蹦极只在旗帜波（大波）出现。&lt;br&gt;限制红眼后，红眼只在所选的波次出现（总共 20 波）。&lt;/p&gt;
&lt;p&gt;简略模式下使用自然出怪，普僵必出。&lt;/p&gt;
&lt;p&gt;简略模式下使用极限出怪，普僵旗帜必出，限制旗帜雪人蹦极，不限制红眼。&lt;/p&gt;
&lt;p&gt;详细模式下使用模拟自然出怪，普僵旗帜必出，限制旗帜雪人蹦极。&lt;/p&gt;
&lt;h2&gt;布阵&lt;/h2&gt;
&lt;p&gt;勾选“快捷布阵模式”会开启这些功能：自动收集、玉米炮无冷却、植物无敌、暂停出怪、无视阳光、卡片无冷却、紫卡无限制、浓雾透视。&lt;/p&gt;
&lt;p&gt;点击“快速过关”后会直接结束本关卡，秒杀所有场上僵尸，并将阳光数设置为 8000，关卡数设置为 1010（已完成 2022 面旗帜数）。可以在点击后立即暂停游戏并去对应的页面修改阳光和关卡数。&lt;/p&gt;
&lt;p&gt;布阵字符串格式和 &lt;a href=&quot;https://pvz.lmintlcx.com/lineup/&quot;&gt;网页布阵器&lt;/a&gt; 互通。&lt;/p&gt;
&lt;p&gt;内置布阵字符串包括一些贴吧 &lt;a href=&quot;https://tieba.baidu.com/f?kw=植物大战僵尸&amp;ie=utf-8&amp;tab=good&quot;&gt;精品区&lt;/a&gt; 知名阵型。玩家可根据需要调整阵型，不需要完全遵循原阵。&lt;/p&gt;
&lt;p&gt;点击“更新”后会联网更新内置的阵型列表。个人整理，随缘更新。&lt;/p&gt;
&lt;p&gt;修改游戏场地可能会造成一些不为人知的问题，因此“允许切换场景”选项默认不勾选。建议用 &lt;a href=&quot;https://pvz.lmintlcx.com/pvztoolsdemo/hiddenscene/&quot;&gt;更加常规的方法&lt;/a&gt; 进入隐藏场地再混乱到“生存无尽”模式。&lt;/p&gt;
&lt;p&gt;勾选“保持血量状态”后，导入或导出字符串时部分植物（坚果、高坚果、南瓜头、大蒜、地刺王）的残血状态会得到保留。&lt;/p&gt;
&lt;h2&gt;其他&lt;/h2&gt;
&lt;p&gt;“打开存档目录”功能在 XP 系统上暂时不可用（存档文件位于游戏目录内的“userdata”文件夹）。对于 Vista 以及更高版本的系统，存档文件位于“C:\ProgramData\PopCap Games\PlantsVsZombies\userdata\”文件夹。&lt;/p&gt;
&lt;p&gt;解包文件位于指定的文件夹内。而打包文件会以“main_&amp;lt;数字&amp;gt;.pak”的格式命名，请将其改名为“main.pak”并且替换掉原来的游戏文件（记得先备份）。&lt;/p&gt;</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5797"/>
        <source>Document</source>
        <translation>文档</translation>
    </message>
</context>
<context>
    <name>Pt::EffectPage</name>
    <message>
        <location filename="../src/pages.cpp" line="4539"/>
        <source>Ice Trail Coordinate</source>
        <translation>冰道坐标</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4541"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4543"/>
        <source>Fullscreen Fog</source>
        <translation>全屏浓雾</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4544"/>
        <source>Clear Fog</source>
        <translation>清除浓雾</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4545"/>
        <source>Transparent Vase</source>
        <translation>罐子透视</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4546"/>
        <source>Ignore Slope</source>
        <translation>无视斜坡</translation>
    </message>
</context>
<context>
    <name>Pt::GardenPage</name>
    <message>
        <location filename="../src/pages.cpp" line="3857"/>
        <source>Fertilizer Unlimited</source>
        <translation>花肥无限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3858"/>
        <source>Bug Spray Unlimited</source>
        <translation>杀虫剂无限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3859"/>
        <source>Chocolate Unlimited</source>
        <translation>巧克力无限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3860"/>
        <source>Tree Food Unlimited</source>
        <translation>树肥无限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3862"/>
        <source>Wisdom Tree Height</source>
        <translation>智慧树高度</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3863"/>
        <location filename="../src/pages.cpp" line="3867"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3865"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3866"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3869"/>
        <source>Scene</source>
        <translation>场地</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3870"/>
        <source>Type</source>
        <translation>类型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3871"/>
        <source>Direction</source>
        <translation>方向</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3872"/>
        <source>Color</source>
        <translation>颜色</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3873"/>
        <source>Status</source>
        <translation>状态</translation>
    </message>
</context>
<context>
    <name>Pt::IzeLineupPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5697"/>
        <location filename="../src/pages.cpp" line="5703"/>
        <source>Empty</source>
        <translation>空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5710"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5711"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5712"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5714"/>
        <source>I, Zombie Endless Lineup</source>
        <translation>我是僵尸无尽布阵</translation>
    </message>
</context>
<context>
    <name>Pt::LevelPage</name>
    <message>
        <location filename="../src/pages.cpp" line="236"/>
        <source>Get Gold Sunflower Trophy</source>
        <translation>解锁黄金向日葵奖杯</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="237"/>
        <source>Get All Shop Items</source>
        <translation>获得商店物品</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="238"/>
        <source>Unlock All Mode Temporarily</source>
        <translation>临时解锁所有模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="239"/>
        <source>Level Complete</source>
        <translation>直接过关</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="241"/>
        <location filename="../src/pages.cpp" line="253"/>
        <location filename="../src/pages.cpp" line="256"/>
        <source>Adventure</source>
        <translation>冒险模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="242"/>
        <source>Mini-Games</source>
        <translation>迷你游戏</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="243"/>
        <source>Puzzle</source>
        <translation>解谜模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="244"/>
        <source>Survival</source>
        <translation>生存模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="279"/>
        <source>Modify Mode</source>
        <translation>混乱关卡</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="281"/>
        <source>Window Screenshot</source>
        <translation>窗口截图</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="283"/>
        <source>Tod Mode</source>
        <translation>Tod 模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="284"/>
        <source>Show Limbo Page</source>
        <translation>显示隐藏页面</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="287"/>
        <source>Lock IZE Array</source>
        <translation>锁定 IZE 阵型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="289"/>
        <source>Endless Rounds</source>
        <translation>无尽轮数</translation>
    </message>
</context>
<context>
    <name>Pt::LineupPage</name>
    <message>
        <location filename="../src/pages.cpp" line="3597"/>
        <source>Warning</source>
        <translation>警告</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3532"/>
        <source>Wrong string format!</source>
        <translation>字符串格式错误！</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2944"/>
        <source>Already copied to new format.</source>
        <translation>已复制为新格式。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2949"/>
        <source>Already copied.</source>
        <translation>已复制。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2970"/>
        <source>Already pasted.</source>
        <translation>已粘贴。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2984"/>
        <source>Lineup Mode Shortcut</source>
        <translation>快捷布阵模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2985"/>
        <source>Quick Pass</source>
        <translation>快速过关</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2986"/>
        <source>Modify Mode To Survival Endless</source>
        <translation>混乱到生存无尽</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2987"/>
        <source>&lt;style&gt;a {text-decoration: none}&lt;/style&gt;&lt;a href=&apos;https://pvz.lmintlcx.com/goto/hiddenscene/&apos;&gt;Hidden Scene&lt;/a&gt;</source>
        <translation>&lt;style&gt;a {text-decoration: none}&lt;/style&gt;&lt;a href=&apos;https://pvz.lmintlcx.com/goto/hiddenscene/&apos;&gt;隐藏场地&lt;/a&gt;</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2989"/>
        <source>Turn on a series of features that are convenient for manual lineup.</source>
        <translation>打开一系列方便手动布阵的功能。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2990"/>
        <source>Kill all zombies and end current level directly with 8000 sunshine and 2020 flags.</source>
        <translation>杀死所有僵尸并用 8000 阳光 2020 面旗帜数直接过关。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2993"/>
        <source>Lily Pad On Pool</source>
        <translation>水路睡莲</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2994"/>
        <source>Flower Pot On Roof</source>
        <translation>屋顶花盆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2995"/>
        <source>Clear All Plants</source>
        <translation>清空植物</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3004"/>
        <source>Update</source>
        <translation>更新</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3458"/>
        <source>Unable to connect to network.</source>
        <translation>无法连接到网络。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3482"/>
        <source>Update failed, lineup string database parsing error.</source>
        <translation>更新失败，布阵字符串数据库解析出错。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3501"/>
        <source>Lineup string updated, version %1, total %2.</source>
        <translation>阵型字符串已更新，版本 %1，数量 %2。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3505"/>
        <source>Lineup already up to date, version %1, total %2.</source>
        <translation>阵型已是最新，版本 %1，数量 %2。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3517"/>
        <source>Error while connecting to update server.</source>
        <translation>连接到更新服务器时出错。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3564"/>
        <source>Name</source>
        <translation>名称</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3565"/>
        <source>Please input lineup name:</source>
        <translation>请输入阵型名称：</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3575"/>
        <source>Save failed, name cannot contain character &quot;|&quot;.</source>
        <translation>保存失败，名称中不能包含“|”字符。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3586"/>
        <source>Lineup %1 already saved.</source>
        <translation>阵型 %1 已保存。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3598"/>
        <source>Are you sure you want to delete lineup %1?</source>
        <translation>确定要删除阵型 %1 吗？</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3620"/>
        <source>Lineup %1 already deleted.</source>
        <translation>阵型 %1 已删除。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3005"/>
        <source>One Key Setup</source>
        <translation>一键布阵</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2992"/>
        <source>Clear All Graves</source>
        <translation>清空墓碑</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3003"/>
        <source>&lt;style&gt;a {text-decoration: none}&lt;/style&gt;&lt;a href=&apos;https://pvz.lmintlcx.com/lineup/&apos;&gt;Open Array Design&lt;/a&gt;</source>
        <translation>&lt;style&gt;a {text-decoration: none}&lt;/style&gt;&lt;a href=&apos;https://pvz.lmintlcx.com/lineup/&apos;&gt;打开网页布阵器&lt;/a&gt;</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3007"/>
        <source>String -&gt; Lineup</source>
        <translation>字符串 -&gt; 阵型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3008"/>
        <source>String &lt;- Lineup</source>
        <translation>字符串 &lt;- 阵型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3010"/>
        <source>Copy</source>
        <translation>复制</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3011"/>
        <source>Paste</source>
        <translation>粘贴</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3012"/>
        <source>Save</source>
        <translation>保存</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3013"/>
        <source>Delete</source>
        <translation>删除</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3015"/>
        <source>Allow Switch Scene</source>
        <translation>允许切换场地</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3016"/>
        <source>Keep HP Status</source>
        <translation>保留耐久状态</translation>
    </message>
</context>
<context>
    <name>Pt::List</name>
    <message>
        <location filename="../src/list.cpp" line="56"/>
        <source>Level</source>
        <translation>关卡</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="57"/>
        <source>Resources</source>
        <translation>资源</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="58"/>
        <location filename="../src/list.cpp" line="353"/>
        <source>Plants</source>
        <translation>植物</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="59"/>
        <location filename="../src/list.cpp" line="354"/>
        <source>Zombies</source>
        <translation>僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="60"/>
        <source>Spawn</source>
        <translation>出怪</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="61"/>
        <source>Slots</source>
        <translation>卡槽</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="62"/>
        <location filename="../src/list.cpp" line="518"/>
        <source>Scene</source>
        <translation>场地</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="63"/>
        <source>Lineup</source>
        <translation>布阵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="64"/>
        <source>Garden</source>
        <translation>花园</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="65"/>
        <location filename="../src/list.cpp" line="349"/>
        <source>Vase</source>
        <translation>罐子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="66"/>
        <source>Effects</source>
        <translation>特效</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="67"/>
        <source>Others</source>
        <translation>杂项</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="68"/>
        <source>Status</source>
        <translation>状态</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="428"/>
        <source>Peashooter</source>
        <translation>豌豆射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="296"/>
        <location filename="../src/list.cpp" line="434"/>
        <source>Chomper</source>
        <translation>大嘴花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="225"/>
        <location filename="../src/list.cpp" line="295"/>
        <location filename="../src/list.cpp" line="432"/>
        <source>Potato Mine</source>
        <translation>土豆雷</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="449"/>
        <source>Spikeweed</source>
        <translation>地刺</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="457"/>
        <source>Starfruit</source>
        <translation>杨桃</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="438"/>
        <source>Fume-shroom</source>
        <translation>大喷菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="301"/>
        <location filename="../src/list.cpp" line="459"/>
        <source>Magnet-shroom</source>
        <translation>磁力菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="441"/>
        <source>Scaredy-shroom</source>
        <translation>胆小菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="133"/>
        <source>ZomBotany</source>
        <translation>植物僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="134"/>
        <source>Wall-nut Bowling</source>
        <translation>坚果保龄球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="135"/>
        <source>Slot Machine</source>
        <translation>老虎机</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="136"/>
        <source>It&apos;s Raining Seeds</source>
        <translation>雨中种植物</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="137"/>
        <source>Beghouled</source>
        <translation>宝石迷阵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="138"/>
        <source>Invisi-ghoul</source>
        <translation>隐形食脑者</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="139"/>
        <source>Seeing Stars</source>
        <translation>看星星</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="140"/>
        <source>Zombiquarium</source>
        <translation>僵尸水族馆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="141"/>
        <source>Beghouled Twist</source>
        <translation>宝石迷阵转转看</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="142"/>
        <source>Big Trouble Little Zombie</source>
        <translation>小僵尸大麻烦</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="143"/>
        <source>Portal Combat</source>
        <translation>保护传送门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="144"/>
        <source>Column Like You See&apos;Em</source>
        <translation>你看，他们像柱子一样</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="145"/>
        <source>Bobseld Bonanza</source>
        <translation>雪橇区</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="146"/>
        <source>Zombie Nimble Zombie Quick</source>
        <translation>僵尸快跑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="147"/>
        <source>Whack a Zombie</source>
        <translation>锤僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="148"/>
        <source>Last Stand</source>
        <translation>谁笑到最后</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="149"/>
        <source>ZomBotany 2</source>
        <translation>植物僵尸 2</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="150"/>
        <source>Wall-nut Bowling 2</source>
        <translation>坚果保龄球 2</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="151"/>
        <source>Pogo Party</source>
        <translation>跳跳舞会</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="152"/>
        <source>Dr. Zomboss&apos;s Revenge</source>
        <translation>僵王博士的复仇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="153"/>
        <source>Art Challenge Wall-nut</source>
        <translation>坚果艺术</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="154"/>
        <source>Sunny Day</source>
        <translation>晴天</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="155"/>
        <source>Unsodded</source>
        <translation>无草皮之地</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="156"/>
        <source>Big Time</source>
        <translation>重要时间</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="157"/>
        <source>Art Challenge Sunflower</source>
        <translation>太阳花艺术</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="158"/>
        <source>Air Raid</source>
        <translation>空袭</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="159"/>
        <source>Ice Level</source>
        <translation>冰冻关卡</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="160"/>
        <location filename="../src/list.cpp" line="325"/>
        <location filename="../src/list.cpp" line="525"/>
        <source>Zen Garden</source>
        <translation>禅境花园</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="161"/>
        <source>High Gravity</source>
        <translation>超乎寻常的压力</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="162"/>
        <source>Grave Danger</source>
        <translation>坟墓模式</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="163"/>
        <location filename="../src/list.cpp" line="182"/>
        <source>Can You Dig It?</source>
        <translation>你能把它挖出来吗？</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="164"/>
        <source>Dark Stormy Night</source>
        <translation>暴风雨之夜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="165"/>
        <source>Bungee Blitz</source>
        <translation>蹦极闪电战</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="166"/>
        <source>Squirrel</source>
        <translation>松鼠</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="167"/>
        <location filename="../src/list.cpp" line="327"/>
        <source>Tree of Wisdom</source>
        <translation>智慧树</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="170"/>
        <source>Vasebreaker</source>
        <translation>破罐者</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="171"/>
        <source>To the Left</source>
        <translation>一路向左</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="172"/>
        <source>Third Vase</source>
        <translation>第三个罐子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="173"/>
        <source>Chain Reaction</source>
        <translation>连锁反应</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="174"/>
        <source>M is for Metal</source>
        <translation>M 的意思是金属</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="175"/>
        <source>Scary Potter</source>
        <translation>胆怯的制陶工</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="176"/>
        <source>Hokey Pokey</source>
        <translation>变戏法</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="177"/>
        <source>Another Chain Reaction</source>
        <translation>另一个连锁反应</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="178"/>
        <source>Ace of Vase</source>
        <translation>罐子王牌</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="179"/>
        <source>Vasebreaker Endless</source>
        <translation>无尽的试炼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="180"/>
        <source>I, Zombie</source>
        <translation>我是僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="181"/>
        <source>I, Zombie Too</source>
        <translation>我也是僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="183"/>
        <source>Totally Nuts</source>
        <translation>完全傻了</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="184"/>
        <source>Dead Zeppelin</source>
        <translation>死亡飞艇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="185"/>
        <source>Me Smash!</source>
        <translation>我烂了！</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="186"/>
        <source>ZomBoogie</source>
        <translation>僵尸摇摆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="187"/>
        <source>Three Hit Wonder</source>
        <translation>三连击</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="188"/>
        <source>All your brainz r belong to us</source>
        <translation>你所有大脑都是属于我的</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="189"/>
        <source>I, Zombie Endless</source>
        <translation>我是僵尸无尽版</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="190"/>
        <source>Upsell</source>
        <translation>追加销售</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="191"/>
        <source>Intro</source>
        <translation>介绍</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="194"/>
        <source>Survival: Day</source>
        <translation>生存模式：白天</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="195"/>
        <source>Survival: Night</source>
        <translation>生存模式：黑夜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="196"/>
        <source>Survival: Pool</source>
        <translation>生存模式：泳池</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="197"/>
        <source>Survival: Fog</source>
        <translation>生存模式：浓雾</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="198"/>
        <source>Survival: Roof</source>
        <translation>生存模式：屋顶</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="199"/>
        <source>Survival: Day (Hard)</source>
        <translation>生存模式：白天（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="200"/>
        <source>Survival: Night (Hard)</source>
        <translation>生存模式：黑夜（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="201"/>
        <source>Survival: Pool (Hard)</source>
        <translation>生存模式：泳池（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="202"/>
        <source>Survival: Fog (Hard)</source>
        <translation>生存模式：浓雾（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="203"/>
        <source>Survival: Roof (Hard)</source>
        <translation>生存模式：屋顶（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="204"/>
        <source>Survival: Day (Endless)</source>
        <translation>生存模式：白天（无尽版）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="205"/>
        <source>Survival: Night (Endless)</source>
        <translation>生存模式：黑夜（无尽版）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="206"/>
        <source>Survival: Endless</source>
        <translation>生存模式：无尽版</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="207"/>
        <source>Survival: Fog (Endless)</source>
        <translation>生存模式：浓雾（无尽版）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="208"/>
        <source>Survival: Roof (Endless)</source>
        <translation>生存模式：屋顶（无尽版）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="211"/>
        <source>Pea</source>
        <translation>豌豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="212"/>
        <source>Frozen Pea</source>
        <translation>冰豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="213"/>
        <source>Cabbage</source>
        <translation>卷心菜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="214"/>
        <source>Melon</source>
        <translation>西瓜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="215"/>
        <source>Fume</source>
        <translation>烟雾</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="216"/>
        <location filename="../src/list.cpp" line="472"/>
        <source>Winter Melon</source>
        <translation>冰瓜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="217"/>
        <source>Fireball</source>
        <translation>火球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="218"/>
        <source>Star</source>
        <translation>星星</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="219"/>
        <source>Spike</source>
        <translation>尖刺</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="220"/>
        <source>Basketball</source>
        <translation>篮球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="221"/>
        <source>Kernel</source>
        <translation>玉米</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="222"/>
        <source>Butter</source>
        <translation>黄油</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="223"/>
        <source>Zombie Pea</source>
        <translation>僵尸豌豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="224"/>
        <source>Ash</source>
        <translation>灰烬</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="226"/>
        <location filename="../src/list.cpp" line="298"/>
        <location filename="../src/list.cpp" line="442"/>
        <source>Ice-shroom</source>
        <translation>寒冰菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="227"/>
        <location filename="../src/list.cpp" line="445"/>
        <source>Squash</source>
        <translation>倭瓜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="228"/>
        <source>Bite</source>
        <translation>啃咬</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="232"/>
        <location filename="../src/list.cpp" line="431"/>
        <source>Wall-nut</source>
        <translation>坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="233"/>
        <location filename="../src/list.cpp" line="451"/>
        <source>Tall-nut</source>
        <translation>高坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="234"/>
        <location filename="../src/list.cpp" line="458"/>
        <source>Pumpkin</source>
        <translation>南瓜头</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="235"/>
        <location filename="../src/list.cpp" line="464"/>
        <source>Garlic</source>
        <translation>大蒜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="236"/>
        <location filename="../src/list.cpp" line="474"/>
        <source>Spikerock</source>
        <translation>地刺王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="238"/>
        <location filename="../src/list.cpp" line="489"/>
        <source>Conehead Zombie</source>
        <translation>路障</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="239"/>
        <location filename="../src/list.cpp" line="490"/>
        <source>Pole Vaulting Zombie</source>
        <translation>撑杆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="240"/>
        <location filename="../src/list.cpp" line="491"/>
        <source>Buckethead Zombie</source>
        <translation>铁桶</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="241"/>
        <source>Newspaper Zombie</source>
        <translation>读报</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="242"/>
        <location filename="../src/list.cpp" line="497"/>
        <source>Screen Door Zombie</source>
        <translation>铁门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="243"/>
        <location filename="../src/list.cpp" line="495"/>
        <source>Football Zombie</source>
        <translation>橄榄</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="244"/>
        <location filename="../src/list.cpp" line="500"/>
        <source>Dancing Zombie</source>
        <translation>舞王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="245"/>
        <location filename="../src/list.cpp" line="498"/>
        <source>Zomboni</source>
        <translation>冰车</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="246"/>
        <source>Dolphin Rider Zombie</source>
        <translation>海豚</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="247"/>
        <source>Jack-in-the-Box Zombie</source>
        <translation>小丑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="248"/>
        <location filename="../src/list.cpp" line="493"/>
        <source>Digger Zombie</source>
        <translation>矿工</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="249"/>
        <location filename="../src/list.cpp" line="499"/>
        <source>Pogo Zombie</source>
        <translation>跳跳</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="250"/>
        <source>Zombie Yeti</source>
        <translation>雪人</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="251"/>
        <location filename="../src/list.cpp" line="494"/>
        <source>Bungee Zombie</source>
        <translation>蹦极</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="252"/>
        <location filename="../src/list.cpp" line="492"/>
        <source>Ladder Zombie</source>
        <translation>扶梯</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="253"/>
        <location filename="../src/list.cpp" line="501"/>
        <source>Gargantuar</source>
        <translation>白眼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="254"/>
        <source>Dr. Zomboss</source>
        <translation>僵王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="255"/>
        <source>Dr. Zomboss Extra</source>
        <translation>僵王附加</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="256"/>
        <source>Wall-nut Zombie</source>
        <translation>坚果僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="257"/>
        <source>Jalapeno Zombie</source>
        <translation>辣椒僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="258"/>
        <source>Tall-nut Zombie</source>
        <translation>高坚果僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="259"/>
        <source>GigaGargantuar</source>
        <translation>红眼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="260"/>
        <source>Imp in I, Zombie</source>
        <translation>我是僵尸小鬼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="261"/>
        <source>Balloon</source>
        <translation>气球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="264"/>
        <source>Silver Coin</source>
        <translation>银币</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="265"/>
        <source>Gold Coin</source>
        <translation>金币</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="266"/>
        <location filename="../src/list.cpp" line="485"/>
        <source>Diamond</source>
        <translation>钻石</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="267"/>
        <location filename="../src/list.cpp" line="484"/>
        <location filename="../src/list.cpp" line="573"/>
        <source>Sun</source>
        <translation>阳光</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="268"/>
        <source>Small Sun</source>
        <translation>小阳光</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="269"/>
        <source>Big Sun</source>
        <translation>大阳光</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="293"/>
        <source>Fog Clear</source>
        <translation>浓雾退散</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="294"/>
        <source>Cherry Bomb / Jalapeno</source>
        <translation>樱桃/辣椒</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="297"/>
        <location filename="../src/list.cpp" line="437"/>
        <source>Sun-shroom</source>
        <translation>阳光菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="299"/>
        <location filename="../src/list.cpp" line="443"/>
        <source>Doom-shroom</source>
        <translation>毁灭菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="300"/>
        <location filename="../src/list.cpp" line="455"/>
        <source>Blover</source>
        <translation>三叶草</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="302"/>
        <source>Cob Cannon Filling</source>
        <translation>玉米炮装填</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="303"/>
        <source>Backup Dancer Call</source>
        <translation>召唤伴舞</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="304"/>
        <source>Zombie Yeti Run Away</source>
        <translation>雪人逃跑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="305"/>
        <source>Bungee Zombie Stay</source>
        <translation>蹦极停留</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="308"/>
        <source>Lawn</source>
        <translation>草地</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="309"/>
        <source>Bare</source>
        <translation>裸地</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="310"/>
        <location filename="../src/list.cpp" line="320"/>
        <source>Pool</source>
        <translation>泳池</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="313"/>
        <location filename="../src/list.cpp" line="564"/>
        <source>None</source>
        <translation>无</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="314"/>
        <source>Land</source>
        <translation>陆路</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="315"/>
        <source>Water</source>
        <translation>水路</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="318"/>
        <source>Day</source>
        <translation>白天</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="319"/>
        <source>Night</source>
        <translation>黑夜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="321"/>
        <source>Fog</source>
        <translation>浓雾</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="322"/>
        <source>Roof</source>
        <translation>屋顶</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="323"/>
        <source>Moon</source>
        <translation>月夜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="324"/>
        <location filename="../src/list.cpp" line="526"/>
        <source>Mushroom Garden</source>
        <translation>蘑菇园</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="326"/>
        <location filename="../src/list.cpp" line="528"/>
        <source>Aquarium Garden</source>
        <translation>水族馆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="344"/>
        <source>Grave</source>
        <translation>墓碑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="345"/>
        <source>Crater</source>
        <translation>弹坑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="346"/>
        <source>Ladder</source>
        <translation>梯子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="347"/>
        <source>White Portal</source>
        <translation>白传送门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="348"/>
        <source>Black Portal</source>
        <translation>黑传送门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="350"/>
        <source>Snail</source>
        <translation>蜗牛</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="351"/>
        <source>Rake</source>
        <translation>钉耙</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="352"/>
        <source>Brain</source>
        <translation>脑子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="357"/>
        <source>Kill</source>
        <translation>秒杀</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="358"/>
        <source>Hypno</source>
        <translation>魅惑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="359"/>
        <source>Freeze</source>
        <translation>冻结</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="360"/>
        <source>Decelerate</source>
        <translation>减速</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="361"/>
        <source>Immobilize</source>
        <translation>固定</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="362"/>
        <source>Blow Away</source>
        <translation>吹走</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="363"/>
        <source>Dying</source>
        <translation>濒死</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="364"/>
        <source>Disappear</source>
        <translation>消失</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="365"/>
        <source>Black</source>
        <translation>变黑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="366"/>
        <source>Bigger</source>
        <translation>变大</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="369"/>
        <source>Zombie</source>
        <comment>Zombie</comment>
        <translation>普僵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="370"/>
        <source>Flag Zombie</source>
        <comment>Zombie</comment>
        <translation>旗帜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="371"/>
        <source>Conehead Zombie</source>
        <comment>Zombie</comment>
        <translation>路障</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="372"/>
        <source>Pole Vaulting Zombie</source>
        <comment>Zombie</comment>
        <translation>撑杆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="373"/>
        <source>Buckethead Zombie</source>
        <comment>Zombie</comment>
        <translation>铁桶</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="374"/>
        <source>Newspaper Zombie</source>
        <comment>Zombie</comment>
        <translation>读报</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="375"/>
        <source>Screen Door Zombie</source>
        <comment>Zombie</comment>
        <translation>铁门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="376"/>
        <source>Football Zombie</source>
        <comment>Zombie</comment>
        <translation>橄榄</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="377"/>
        <source>Dancing Zombie</source>
        <comment>Zombie</comment>
        <translation>舞王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="378"/>
        <source>Backup Dancer</source>
        <comment>Zombie</comment>
        <translation>伴舞</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="379"/>
        <source>Ducky Tube Zombie</source>
        <comment>Zombie</comment>
        <translation>鸭子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="380"/>
        <source>Snorkel Zombie</source>
        <comment>Zombie</comment>
        <translation>潜水</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="381"/>
        <source>Zomboni</source>
        <comment>Zombie</comment>
        <translation>冰车</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="382"/>
        <source>Zombie Bobsled Team</source>
        <comment>Zombie</comment>
        <translation>雪橇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="383"/>
        <source>Dolphin Rider Zombie</source>
        <comment>Zombie</comment>
        <translation>海豚</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="384"/>
        <source>Jack-in-the-Box Zombie</source>
        <comment>Zombie</comment>
        <translation>小丑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="385"/>
        <source>Balloon Zombie</source>
        <comment>Zombie</comment>
        <translation>气球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="386"/>
        <source>Digger Zombie</source>
        <comment>Zombie</comment>
        <translation>矿工</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="387"/>
        <source>Pogo Zombie</source>
        <comment>Zombie</comment>
        <translation>跳跳</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="388"/>
        <source>Zombie Yeti</source>
        <comment>Zombie</comment>
        <translation>雪人</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="389"/>
        <source>Bungee Zombie</source>
        <comment>Zombie</comment>
        <translation>蹦极</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="390"/>
        <source>Ladder Zombie</source>
        <comment>Zombie</comment>
        <translation>扶梯</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="391"/>
        <source>Catapult Zombie</source>
        <comment>Zombie</comment>
        <translation>投篮</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="392"/>
        <source>Gargantuar</source>
        <comment>Zombie</comment>
        <translation>白眼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="393"/>
        <source>Imp</source>
        <comment>Zombie</comment>
        <translation>小鬼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="394"/>
        <source>Dr. Zomboss</source>
        <comment>Zombie</comment>
        <translation>僵王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="395"/>
        <source>Peashooter Zombie</source>
        <comment>Zombie</comment>
        <translation>豌豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="396"/>
        <source>Wall-nut Zombie</source>
        <comment>Zombie</comment>
        <translation>坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="397"/>
        <source>Jalapeno Zombie</source>
        <comment>Zombie</comment>
        <translation>辣椒</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="398"/>
        <source>Gatling Pea Zombie</source>
        <comment>Zombie</comment>
        <translation>机枪</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="399"/>
        <source>Squash Zombie</source>
        <comment>Zombie</comment>
        <translation>倭瓜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="400"/>
        <source>Tall-nut Zombie</source>
        <comment>Zombie</comment>
        <translation>高坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="401"/>
        <source>GigaGargantuar</source>
        <comment>Zombie</comment>
        <translation>红眼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="404"/>
        <source>1 slot</source>
        <translation>一格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="405"/>
        <source>2 slots</source>
        <translation>两格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="406"/>
        <source>3 slots</source>
        <translation>三格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="407"/>
        <source>4 slots</source>
        <translation>四格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="408"/>
        <source>5 slots</source>
        <translation>五格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="409"/>
        <source>6 slots</source>
        <translation>六格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="410"/>
        <source>7 slots</source>
        <translation>七格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="411"/>
        <source>8 slots</source>
        <translation>八格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="412"/>
        <source>9 slots</source>
        <translation>九格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="413"/>
        <source>10 slots</source>
        <translation>十格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="567"/>
        <location filename="../src/list.cpp" line="572"/>
        <source>Zombie</source>
        <translation>僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="231"/>
        <source>Plant</source>
        <comment>Normal Plant</comment>
        <translation>普通植物</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="237"/>
        <source>Zombie</source>
        <comment>Normal Zombie</comment>
        <translation>普通僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="488"/>
        <source>Zombie</source>
        <comment>Zombie Zombie</comment>
        <translation>普僵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="486"/>
        <source>Snorkel Zombie</source>
        <translation>潜水</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="496"/>
        <source>Balloon Zombie</source>
        <translation>气球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="502"/>
        <source>Imp</source>
        <translation>小鬼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="416"/>
        <source>1st slot</source>
        <translation>第一格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="417"/>
        <source>2nd slot</source>
        <translation>第二格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="418"/>
        <source>3rd slot</source>
        <translation>第三格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="419"/>
        <source>4th slot</source>
        <translation>第四格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="420"/>
        <source>5th slot</source>
        <translation>第五格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="421"/>
        <source>6th slot</source>
        <translation>第六格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="422"/>
        <source>7th slot</source>
        <translation>第七格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="423"/>
        <source>8th slot</source>
        <translation>第八格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="424"/>
        <source>9th slot</source>
        <translation>第九格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="425"/>
        <source>10th slot</source>
        <translation>第十格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="429"/>
        <source>Sunflower</source>
        <translation>向日葵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="430"/>
        <source>Cherry Bomb</source>
        <translation>樱桃炸弹</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="433"/>
        <source>Snow Pea</source>
        <translation>寒冰射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="435"/>
        <source>Repeater</source>
        <translation>双发射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="436"/>
        <source>Puff-shroom</source>
        <translation>小喷菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="439"/>
        <source>Grave Buster</source>
        <translation>墓碑吞噬者</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="440"/>
        <source>Hypno-shroom</source>
        <translation>魅惑菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="444"/>
        <source>Lily Pad</source>
        <translation>睡莲</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="446"/>
        <source>Threepeater</source>
        <translation>三线射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="447"/>
        <source>Tangle Kelp</source>
        <translation>缠绕海草</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="448"/>
        <source>Jalapeno</source>
        <translation>火爆辣椒</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="450"/>
        <source>Torchwood</source>
        <translation>火炬树桩</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="452"/>
        <source>Sea-shroom</source>
        <translation>海蘑菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="453"/>
        <source>Plantern</source>
        <translation>路灯花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="454"/>
        <source>Cactus</source>
        <translation>仙人掌</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="456"/>
        <source>Split Pea</source>
        <translation>裂荚射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="460"/>
        <source>Cabbage-pult</source>
        <translation>卷心菜投手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="461"/>
        <source>Flower Pot</source>
        <translation>花盆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="462"/>
        <source>Kernel-pult</source>
        <translation>玉米投手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="463"/>
        <source>Coffee Bean</source>
        <translation>咖啡豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="465"/>
        <source>Umbrella Leaf</source>
        <translation>叶子保护伞</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="466"/>
        <source>Marigold</source>
        <translation>金盏花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="467"/>
        <source>Melon-pult</source>
        <translation>西瓜投手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="468"/>
        <source>Gatling Pea</source>
        <translation>机枪射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="469"/>
        <source>Twin Sunflower</source>
        <translation>双子向日葵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="470"/>
        <source>Gloom-shroom</source>
        <translation>忧郁蘑菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="471"/>
        <source>Cattail</source>
        <translation>香蒲</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="473"/>
        <source>Gold Magnet</source>
        <translation>吸金磁</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="475"/>
        <source>Cob Cannon</source>
        <translation>玉米加农炮</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="476"/>
        <location filename="../src/list.cpp" line="536"/>
        <source>Imitater</source>
        <translation>模仿者</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="477"/>
        <source>Explode-o-nut</source>
        <translation>爆炸坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="478"/>
        <source>Giant Wall-nut</source>
        <translation>巨大坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="479"/>
        <location filename="../src/list.cpp" line="550"/>
        <source>Sprout</source>
        <translation>幼苗</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="480"/>
        <source>Reverse Repeater</source>
        <translation>左向双发射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="481"/>
        <source>Nothing</source>
        <translation>无</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="482"/>
        <source>Shuffle plant</source>
        <translation>转向</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="483"/>
        <source>Refill crator</source>
        <translation>消除弹坑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="487"/>
        <source>Trophy</source>
        <translation>奖杯</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="503"/>
        <source>&lt;Missing&gt;</source>
        <translation>&lt;消失&gt;</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="506"/>
        <source>All Rows</source>
        <translation>所有行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="507"/>
        <source>1st Row</source>
        <translation>第一行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="508"/>
        <source>2nd Row</source>
        <translation>第二行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="509"/>
        <source>3rd Row</source>
        <translation>第三行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="510"/>
        <source>4th Row</source>
        <translation>第四行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="511"/>
        <source>5th Row</source>
        <translation>第五行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="512"/>
        <source>6th Row</source>
        <translation>第六行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="515"/>
        <location filename="../src/list.cpp" line="556"/>
        <source>Index</source>
        <translation>序号</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="516"/>
        <location filename="../src/list.cpp" line="557"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="517"/>
        <location filename="../src/list.cpp" line="558"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="519"/>
        <location filename="../src/list.cpp" line="560"/>
        <source>Type</source>
        <translation>类型</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="520"/>
        <source>Direction</source>
        <translation>方向</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="521"/>
        <source>Color</source>
        <translation>颜色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="522"/>
        <source>Status</source>
        <comment>grow up status</comment>
        <translation>状态</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="527"/>
        <source>Wheel Barrow</source>
        <translation>手推车</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="531"/>
        <source>Right</source>
        <translation>右</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="532"/>
        <source>Left</source>
        <translation>左</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="535"/>
        <source>Original</source>
        <translation>原色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="537"/>
        <source>White</source>
        <translation>白色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="538"/>
        <source>Magenta</source>
        <translation>品红色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="539"/>
        <source>Orange</source>
        <translation>橙色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="540"/>
        <source>Pink</source>
        <translation>粉红色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="541"/>
        <source>Cyan</source>
        <translation>青色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="542"/>
        <source>Red</source>
        <translation>红色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="543"/>
        <source>Blue</source>
        <translation>蓝色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="544"/>
        <source>Purple</source>
        <translation>紫色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="545"/>
        <source>Lavender</source>
        <translation>淡紫色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="546"/>
        <source>Yellow</source>
        <translation>黄色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="547"/>
        <source>LightGreen</source>
        <translation>浅绿色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="551"/>
        <source>Small Size</source>
        <translation>小花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="552"/>
        <source>Medium Size</source>
        <translation>中花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="553"/>
        <source>Full Size</source>
        <translation>大花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="559"/>
        <source>Skin</source>
        <translation>皮肤</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="561"/>
        <source>Content</source>
        <translation>内容</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="565"/>
        <source>Unknown</source>
        <translation>未知</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="566"/>
        <location filename="../src/list.cpp" line="571"/>
        <source>Plant</source>
        <translation>植物</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="570"/>
        <source>Empty</source>
        <translation>空</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="576"/>
        <source>Off</source>
        <translation>关闭</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="577"/>
        <source>Spawning</source>
        <translation>出怪</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="578"/>
        <source>Music</source>
        <translation>音乐</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="579"/>
        <source>Memory</source>
        <translation>内存</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="580"/>
        <source>Collision</source>
        <translation>碰撞</translation>
    </message>
</context>
<context>
    <name>Pt::MainWindow</name>
    <message>
        <location filename="../src/window.cpp" line="1563"/>
        <source>Plants vs. Zombies 1.0.0.1051 Toolset</source>
        <translation>植物大战僵尸 1.0.0.1051 辅助工具</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="549"/>
        <location filename="../src/window.cpp" line="564"/>
        <location filename="../src/window.cpp" line="572"/>
        <location filename="../src/window.cpp" line="577"/>
        <source>Update Check</source>
        <translation>更新检查</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="212"/>
        <location filename="../src/window.cpp" line="1737"/>
        <source>Better Choice</source>
        <translation>更好的选择</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="213"/>
        <location filename="../src/window.cpp" line="1738"/>
        <source>PvZ Tools only supports version 1.0.0.1051,
yet PvZ Toolkit supports a dozen versions.

Do you want to download PvZ Toolkit now?</source>
        <translation>PvZ Tools 仅支持 1.0.0.1051。
而 PvZ Toolkit 支持十多个版本。

要现在下载 PvZ Toolkit 吗？</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="549"/>
        <source>Unable to connect to network.</source>
        <translation>无法连接到网络。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="565"/>
        <source>New version detected, download it now?</source>
        <translation>检测到新版本，现在下载吗？</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="572"/>
        <source>This is already the latest release version.</source>
        <translation>已经是最新版。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="577"/>
        <source>Error while connecting to update server.</source>
        <translation>连接到更新服务器时出错。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="619"/>
        <source>Version</source>
        <translation>版本号</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="620"/>
        <source>Date</source>
        <translation>日期</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="621"/>
        <source>Toolchain</source>
        <translation>工具链</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="623"/>
        <source>Copyright</source>
        <translation>版权所有</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="624"/>
        <source>Credit</source>
        <translation>鸣谢</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="627"/>
        <source>About</source>
        <translation>关于</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="632"/>
        <source>&lt;h1&gt;PvZ Tools&lt;/h1&gt;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1649"/>
        <source>Choose File</source>
        <translation>选择文件</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1650"/>
        <source>Choose Folder</source>
        <translation>选择目录</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1651"/>
        <source>Restart</source>
        <translation>重启</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1652"/>
        <source>Exit</source>
        <translation>退出</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1654"/>
        <source>Find Game Again</source>
        <translation>重新查找游戏</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1655"/>
        <source>Game Window Top Most</source>
        <translation>游戏窗口置顶</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1656"/>
        <source>Keep Selected Features</source>
        <translation>维持已选功能</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1671"/>
        <source>Spawning Counting</source>
        <translation>出怪数量统计</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1672"/>
        <source>Target Map Modify</source>
        <translation>目标地图修改</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1673"/>
        <source>Cannon Launcher</source>
        <translation>加农炮发射器</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1674"/>
        <source>Custom Portal</source>
        <translation>自定义传送门</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1675"/>
        <source>I, Zombie Endless</source>
        <translation>我是僵尸无尽</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1677"/>
        <source>Switch Spawn Layout</source>
        <translation>小王子出怪器布局</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1678"/>
        <source>Limit Spawn Species</source>
        <translation>限制出怪种类数</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1679"/>
        <source>Save Selected Species</source>
        <translation>保存已选出怪</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1680"/>
        <source>Mute</source>
        <translation>静音</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1681"/>
        <source>Font</source>
        <translation>字体</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1682"/>
        <source>Restore Default Setting</source>
        <translation>恢复默认设置</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1691"/>
        <source>Help Document</source>
        <translation>帮助文档</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1692"/>
        <source>Video Demo</source>
        <translation>视频演示</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1693"/>
        <source>Visit Website</source>
        <translation>访问网站</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1694"/>
        <source>Change Log</source>
        <translation>更新日志</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1695"/>
        <source>Check Update</source>
        <translation>检查更新</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1696"/>
        <source>About PvZ Tools</source>
        <translation>关于 PvZ Tools</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1697"/>
        <source>About Qt</source>
        <translation>关于 Qt</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1699"/>
        <source>&amp;File</source>
        <translation>文件(&amp;F)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1700"/>
        <source>&amp;Game</source>
        <translation>游戏(&amp;G)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1701"/>
        <source>&amp;Page</source>
        <translation>页面(&amp;P)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1702"/>
        <source>&amp;Setting</source>
        <translation>设置(&amp;S)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1703"/>
        <source>&amp;Language</source>
        <translation>语言(&amp;L)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1704"/>
        <source>&amp;Theme</source>
        <translation>主题(&amp;T)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1705"/>
        <source>&amp;Help</source>
        <translation>帮助(&amp;H)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1707"/>
        <source>Page</source>
        <translation>页面</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1714"/>
        <source>Game found successfully.</source>
        <translation>成功找到游戏。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1734"/>
        <source>Unsupported game version. Try to use PvZ Toolkit instead.</source>
        <translation>不支持的游戏版本。试试使用 PvZ Toolkit 来代替。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1747"/>
        <source>No game window was found. Run Plants vs. Zombies first.</source>
        <translation>未找到游戏窗口。先打开运行植物大战僵尸游戏。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1752"/>
        <source>Error opening game process. Try run Pt as administrator.</source>
        <translation>打开游戏进程出错。建议用管理员权限运行修改器。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1840"/>
        <source>Message</source>
        <translation>信息</translation>
    </message>
</context>
<context>
    <name>Pt::OthersPage</name>
    <message>
        <location filename="../src/pages.cpp" line="4766"/>
        <source>Disable Save Userdata</source>
        <translation>禁止存档</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4767"/>
        <source>Disable Delete Userdata</source>
        <translation>禁止删档</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4769"/>
        <source>Background Running</source>
        <translation>后台运行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4770"/>
        <source>Disable Pause</source>
        <translation>禁用暂停</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4772"/>
        <source>Open Userdata Folder</source>
        <translation>打开存档目录</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4774"/>
        <source>Debug Mode</source>
        <translation>调试模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4776"/>
        <location filename="../src/pages.cpp" line="4779"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4778"/>
        <source>Frame Duration</source>
        <translation>帧间隔</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4781"/>
        <location filename="../src/pages.cpp" line="4797"/>
        <source>Choose File</source>
        <translation>选择文件</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4782"/>
        <source>Extract</source>
        <translation>解包</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4784"/>
        <location filename="../src/pages.cpp" line="4815"/>
        <source>Choose Folder</source>
        <translation>选择目录</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4785"/>
        <source>Pack</source>
        <translation>打包</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4787"/>
        <source>Target Map Modify</source>
        <translation>目标地图修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4788"/>
        <source>Cannon Launcher</source>
        <translation>加农炮发射器</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4789"/>
        <source>Custom Portal</source>
        <translation>自定义传送门</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4790"/>
        <source>I, Zombie Endless</source>
        <translation>我是僵尸无尽</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4799"/>
        <source>PAK files (*.pak) ;; All files (*.*)</source>
        <translation>PAK 文件 (*.pak) ;; 所有文件 (*.*)</translation>
    </message>
</context>
<context>
    <name>Pt::PAK</name>
    <message>
        <location filename="../src/pak.cpp" line="506"/>
        <source>Extract pak Succeeded!</source>
        <translation>解包 pak 成功！</translation>
    </message>
    <message>
        <location filename="../src/pak.cpp" line="510"/>
        <source>Extract pak Failed!</source>
        <translation>解包 pak 失败！</translation>
    </message>
    <message>
        <location filename="../src/pak.cpp" line="523"/>
        <source>Pack pak Succeeded! File name: &quot;%1&quot;.</source>
        <translation>打包 pak 成功！文件名：“%1”。</translation>
    </message>
    <message>
        <location filename="../src/pak.cpp" line="527"/>
        <source>Pack pak Failed!</source>
        <translation>打包 pak 失败！</translation>
    </message>
</context>
<context>
    <name>Pt::PlantsPage</name>
    <message>
        <location filename="../src/pages.cpp" line="894"/>
        <source>Cob Cannon NoCD</source>
        <translation>玉米炮无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="895"/>
        <source>Magnets NoCD</source>
        <translation>磁力菇无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="896"/>
        <source>Potato Mine NoCD</source>
        <translation>土豆雷无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="897"/>
        <source>Chomper NoCD</source>
        <translation>大嘴花无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="899"/>
        <source>Plant Invincible</source>
        <translation>植物无敌</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="900"/>
        <source>Plant Weak</source>
        <translation>植物脆弱</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="901"/>
        <source>Always Kernel</source>
        <translation>只投玉米</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="902"/>
        <source>Always Butter</source>
        <translation>只投黄油</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="904"/>
        <source>No Crater</source>
        <translation>不留弹坑</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="905"/>
        <source>Mushroom Awake</source>
        <translation>蘑菇睡醒</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="906"/>
        <source>Strong Blover</source>
        <translation>强力三叶草</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="907"/>
        <source>Strong Peas</source>
        <translation>强力豌豆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="909"/>
        <source>Explode Immediately</source>
        <translation>灰烬瞬爆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="910"/>
        <source>Explode Never</source>
        <translation>灰烬不爆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="911"/>
        <source>Beghouled Free Move</source>
        <translation>宝石随便移</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="912"/>
        <source>Attack Superposition</source>
        <translation>攻击重叠</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="914"/>
        <source>Plant Torchwood</source>
        <translation>植物火炬</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="915"/>
        <source>Plant Garlic</source>
        <translation>植物大蒜</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="916"/>
        <source>Plant Umbrella</source>
        <translation>植物保护伞</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="917"/>
        <source>Plant Paper</source>
        <translation>植物纸板</translation>
    </message>
</context>
<context>
    <name>Pt::PortalPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5589"/>
        <location filename="../src/pages.cpp" line="5591"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5590"/>
        <location filename="../src/pages.cpp" line="5592"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5593"/>
        <source>Black1</source>
        <translation>黑1</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5594"/>
        <source>Black2</source>
        <translation>黑2</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5595"/>
        <source>White1</source>
        <translation>白1</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5596"/>
        <source>White2</source>
        <translation>白2</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5598"/>
        <source>Start</source>
        <translation>启动</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5599"/>
        <source>Lock</source>
        <translation>锁定</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5600"/>
        <source>Set Portal</source>
        <translation>设置传送门</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5602"/>
        <source>Portal</source>
        <translation>传送门</translation>
    </message>
</context>
<context>
    <name>Pt::PvZ</name>
    <message>
        <location filename="../src/pvz.cpp" line="284"/>
        <source>Already unlocked golden sunflower trophy.</source>
        <translation>已经解锁黄金向日葵奖杯。</translation>
    </message>
    <message>
        <location filename="../src/pvz.cpp" line="332"/>
        <source>Already get all shop items.</source>
        <translation>已经得到所有商店物品。</translation>
    </message>
    <message>
        <location filename="../src/pvz.cpp" line="453"/>
        <source>Screenshot has been copied to clipboard successfully.</source>
        <translation>截图已成功地复制到剪贴板。</translation>
    </message>
    <message>
        <location filename="../src/pvz.cpp" line="2913"/>
        <location filename="../src/pvz.cpp" line="3181"/>
        <source>The current mode is not &apos;Survival: Endless&apos; or &apos;I, Zombie&apos;.</source>
        <translation>当前模式不是“生存无尽”或者“我是僵尸”。</translation>
    </message>
    <message>
        <location filename="../src/pvz.cpp" line="2931"/>
        <location filename="../src/pvz.cpp" line="3187"/>
        <source>The target lineup scene is inconsistent with the current scene.</source>
        <translation>目标阵型场地和当前场地不一致。</translation>
    </message>
    <message>
        <location filename="../src/pvz.cpp" line="3099"/>
        <source>Wrong string format!</source>
        <translation>字符串格式错误！</translation>
    </message>
</context>
<context>
    <name>Pt::ResourcePage</name>
    <message>
        <location filename="../src/pages.cpp" line="510"/>
        <location filename="../src/pages.cpp" line="512"/>
        <location filename="../src/pages.cpp" line="514"/>
        <location filename="../src/pages.cpp" line="516"/>
        <location filename="../src/pages.cpp" line="622"/>
        <source>Value</source>
        <translation>价值</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="541"/>
        <location filename="../src/pages.cpp" line="543"/>
        <location filename="../src/pages.cpp" line="626"/>
        <source>Damage</source>
        <translation>伤害</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="574"/>
        <location filename="../src/pages.cpp" line="576"/>
        <location filename="../src/pages.cpp" line="630"/>
        <source>HP</source>
        <translation>血量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="574"/>
        <source>Accessories</source>
        <translation>饰品</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="603"/>
        <source>Sun</source>
        <translation>阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="604"/>
        <location filename="../src/pages.cpp" line="607"/>
        <location filename="../src/pages.cpp" line="610"/>
        <location filename="../src/pages.cpp" line="613"/>
        <location filename="../src/pages.cpp" line="624"/>
        <location filename="../src/pages.cpp" line="628"/>
        <location filename="../src/pages.cpp" line="632"/>
        <location filename="../src/pages.cpp" line="636"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="606"/>
        <source>Sun Limit</source>
        <translation>阳光上限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="609"/>
        <source>Money</source>
        <translation>金钱</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="612"/>
        <source>Money Limit</source>
        <translation>金钱上限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="615"/>
        <source>Many Falling Sun</source>
        <translation>漫天阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="616"/>
        <source>No Falling Sun</source>
        <translation>不掉阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="617"/>
        <source>Automatic Collected</source>
        <translation>自动收集</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="618"/>
        <source>Not Drop Loot</source>
        <translation>不掉战利品</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="620"/>
        <source>This feature is available when &quot;Automatic Collected&quot; is turned on.</source>
        <translation>这个功能只有在“自动收集”打开时可用。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="634"/>
        <source>Time</source>
        <translation>时间</translation>
    </message>
</context>
<context>
    <name>Pt::ScenePage</name>
    <message>
        <location filename="../src/pages.cpp" line="2607"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2608"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2618"/>
        <source>Planting</source>
        <translation>种植</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2619"/>
        <source>Imitater</source>
        <translation>模仿者</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2629"/>
        <source>Put</source>
        <translation>放置</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2631"/>
        <source>Grave</source>
        <translation>墓碑</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2632"/>
        <source>Rake</source>
        <translation>钉耙</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2634"/>
        <source>Coin</source>
        <translation>物品</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2635"/>
        <source>Ladder</source>
        <translation>梯子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2636"/>
        <source>Ladder Pumpkin</source>
        <translation>南瓜梯子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2637"/>
        <source>Imitater Only</source>
        <translation>仅白南瓜</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2639"/>
        <source>Block Type</source>
        <translation>格子类型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2647"/>
        <location filename="../src/pages.cpp" line="2657"/>
        <location filename="../src/pages.cpp" line="2669"/>
        <location filename="../src/pages.cpp" line="2685"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2649"/>
        <source>Row Type (Spawn)</source>
        <translation>行判定（出怪）</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2659"/>
        <source>Game Scene</source>
        <translation>游戏场景</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2671"/>
        <source>Start Lawn Mowers</source>
        <translation>启动推车</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2672"/>
        <source>Clear Lawn Mowers</source>
        <translation>清除推车</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2673"/>
        <source>Reset Lawn Mowers</source>
        <translation>恢复推车</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2675"/>
        <source>Background Music</source>
        <translation>背景音乐</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2688"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
</context>
<context>
    <name>Pt::SlotsPage</name>
    <message>
        <location filename="../src/pages.cpp" line="2215"/>
        <location filename="../src/pages.cpp" line="2232"/>
        <location filename="../src/pages.cpp" line="2254"/>
        <location filename="../src/pages.cpp" line="2257"/>
        <location filename="../src/pages.cpp" line="2260"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2217"/>
        <source>Top Slots</source>
        <translation>置顶卡槽</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2218"/>
        <source>Hide Slots</source>
        <translation>隐藏卡槽</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2219"/>
        <source>Show Shovel</source>
        <translation>显示铲子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2220"/>
        <source>Shovel Continuously</source>
        <translation>连续铲子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2233"/>
        <source>Imitater</source>
        <translation>模仿者</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2234"/>
        <source>Hide</source>
        <translation>隐藏</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2236"/>
        <source>Ignore Sun</source>
        <translation>无视阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2237"/>
        <source>Cancel Cool Down</source>
        <translation>取消冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2238"/>
        <source>Purple Seed Unlimited</source>
        <translation>紫卡直种</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2239"/>
        <source>Placed Anywhere</source>
        <translation>随意放置</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2240"/>
        <source>Seamless Conveyor Belt</source>
        <translation>无缝传送</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2241"/>
        <source>Hide Menu Button</source>
        <translation>隐藏菜单键</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2243"/>
        <source>Seed</source>
        <translation>卡片</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2253"/>
        <source>Speed</source>
        <translation>攻速</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2256"/>
        <source>Cost</source>
        <translation>价格</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2259"/>
        <source>Recharge</source>
        <translation>冷却</translation>
    </message>
</context>
<context>
    <name>Pt::SpawnBriefPage</name>
    <message>
        <location filename="../src/pages.cpp" line="1436"/>
        <source>Natural (Built-in Generate)</source>
        <translation>自然 (游戏生成)</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1437"/>
        <source>Extreme (Filling Evenly)</source>
        <translation>极限 (均匀填充)</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1439"/>
        <source>Switch Detailed Mode</source>
        <translation>切换详细模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1440"/>
        <source>Spawning Counting</source>
        <translation>出怪数量统计</translation>
    </message>
</context>
<context>
    <name>Pt::SpawnCountPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5124"/>
        <source>Spawning Counting</source>
        <translation>出怪数量统计</translation>
    </message>
</context>
<context>
    <name>Pt::SpawnDetailedPage</name>
    <message>
        <location filename="../src/pages.cpp" line="1798"/>
        <source>Set Seed</source>
        <translation>修改种子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1809"/>
        <source>Add &gt;&gt;</source>
        <translation>添加 &gt;&gt;</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1810"/>
        <source>&lt;&lt; Delete</source>
        <translation>&lt;&lt; 删除</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1811"/>
        <source>Clear List</source>
        <translation>清空列表</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1813"/>
        <source>Natural Spawn</source>
        <translation>自然出怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1814"/>
        <source>Extreme Spawn</source>
        <translation>极限出怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1815"/>
        <source>Simulate Natural Spawn</source>
        <translation>模拟自然出怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1817"/>
        <source>Calls built-in function of game to generates zombies list.</source>
        <translation>调用游戏内置函数生成出怪列表。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1818"/>
        <source>Continuously and evenly populate the zombies list.</source>
        <translation>连续均匀地填充满出怪列表。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1819"/>
        <source>Randomly fill the zombies list according to some ratio.</source>
        <translation>按照一定比例随机填充出怪列表。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1821"/>
        <source>Limit Flag</source>
        <translation>限制旗帜</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1822"/>
        <source>Limit Yeti</source>
        <translation>限制雪人</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1823"/>
        <source>Limit Bungee</source>
        <translation>限制蹦极</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1824"/>
        <source>Limit Giga</source>
        <translation>限制红眼</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1826"/>
        <source>Weight of GigaGargantuar in non huge waves:</source>
        <translation>非大波红眼权重：</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1828"/>
        <source>Flag Zombie will only appear in each flag wave (huge wave).</source>
        <translation>旗帜只在每个旗帜波（大波）出现一只。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1829"/>
        <source>There will be only one Zombie Yeti.</source>
        <translation>雪人只出现一只。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1830"/>
        <source>Bungee Zombie will only appear in flag wave (huge wave).</source>
        <translation>蹦极只在旗帜波（大波）出现。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1831"/>
        <source>GigaGargantuar will only appear in selected wave(s) (20 waves total).</source>
        <translation>红眼只在所选的波次出现（总共 20 波）。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1833"/>
        <source>These check boxes shows or controls the waves of GigaGargantuar appear.</source>
        <translation>这些选项框显示或者控制红眼的出现波数。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1835"/>
        <source>Reset</source>
        <translation>还原</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1836"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1838"/>
        <source>Switch Brief Mode</source>
        <translation>切换简略模式</translation>
    </message>
</context>
<context>
    <name>Pt::StatusPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5002"/>
        <source>Auto Refresh</source>
        <translation>自动刷新</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5004"/>
        <source>Game Mode</source>
        <translation>游戏模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5005"/>
        <source>Game UI</source>
        <translation>游戏界面</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5006"/>
        <source>Running Time</source>
        <translation>进行时间</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5007"/>
        <source>Level Completed</source>
        <translation>完成轮数</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5008"/>
        <source>Total Waves</source>
        <translation>本轮总波数</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5009"/>
        <source>Past Waves</source>
        <translation>已刷新波数</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5010"/>
        <source>Total HP</source>
        <translation>本波总血量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5011"/>
        <source>Trigger HP</source>
        <translation>刷新触发血量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5012"/>
        <source>Count Down</source>
        <translation>刷新倒计时</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5013"/>
        <source>Huge Wave Count Down</source>
        <translation>大波刷新倒计时</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5014"/>
        <source>Plant Count</source>
        <translation>植物数量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5015"/>
        <source>Zombie Count</source>
        <translation>僵尸数量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5026"/>
        <source>Adventure</source>
        <translation>冒险模式</translation>
    </message>
</context>
<context>
    <name>Pt::TargetMapPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5290"/>
        <location filename="../src/pages.cpp" line="5296"/>
        <source>Empty</source>
        <translation>空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5307"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5308"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5309"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5314"/>
        <source>Target Map Modify</source>
        <translation>目标地图修改</translation>
    </message>
</context>
<context>
    <name>Pt::VasePage</name>
    <message>
        <location filename="../src/pages.cpp" line="4067"/>
        <location filename="../src/pages.cpp" line="4200"/>
        <location filename="../src/pages.cpp" line="4243"/>
        <source>Vase Count</source>
        <translation>花瓶数量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4201"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4202"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4203"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4205"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4206"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4207"/>
        <source>Skin</source>
        <translation>皮肤</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4208"/>
        <source>Type</source>
        <translation>类型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4209"/>
        <source>Plant</source>
        <translation>植物</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4210"/>
        <source>Zombie</source>
        <translation>僵尸</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4211"/>
        <source>Sun</source>
        <translation>阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4264"/>
        <location filename="../src/pages.cpp" line="4298"/>
        <source>Empty</source>
        <translation>空</translation>
    </message>
</context>
<context>
    <name>Pt::ZombiesPage</name>
    <message>
        <location filename="../src/pages.cpp" line="1232"/>
        <source>Immediately Explode</source>
        <translation>立即爆炸</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1233"/>
        <source>Never Explode</source>
        <translation>从不爆炸</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1235"/>
        <source>Zombie Invisible</source>
        <translation>僵尸隐形</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1236"/>
        <source>Zombie Show</source>
        <translation>僵尸现形</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1238"/>
        <source>Zombie Invincible</source>
        <translation>僵尸无敌</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1239"/>
        <source>Zombie Weak</source>
        <translation>僵尸虚弱</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1241"/>
        <source>Spawning Paused</source>
        <translation>暂停刷怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1242"/>
        <source>Stay In Place</source>
        <translation>停滞不前</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1244"/>
        <source>No Ice Slow Down</source>
        <translation>屏蔽寒冰减速</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1245"/>
        <source>No Butter Immobilize</source>
        <translation>屏蔽黄油固定</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1246"/>
        <source>No 3 Zombies Group</source>
        <translation>屏蔽三人组</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1247"/>
        <source>No Ice Trail</source>
        <translation>不留冰道</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1249"/>
        <source>No Throw Imp</source>
        <translation>不扔小鬼</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1250"/>
        <source>Gargantuar Eatable</source>
        <translation>巨人可被吃</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1251"/>
        <source>Zomboss No Move</source>
        <translation>僵王不动</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1252"/>
        <source>Balloon Burst</source>
        <translation>气球自爆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1254"/>
        <source>Gather Zombies</source>
        <translation>吸怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1256"/>
        <source>Next Wave</source>
        <translation>下一波</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1258"/>
        <source>All Zombies</source>
        <translation>所有僵尸</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1260"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
</context>
</TS>
