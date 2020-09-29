<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="zh_CN">
<context>
    <name>Pt::CannonLauncherPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5011"/>
        <source>Index</source>
        <translation>序号</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5012"/>
        <location filename="../src/pages.cpp" line="5038"/>
        <source>Not Found</source>
        <translation>未找到</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5014"/>
        <source>Grid</source>
        <translation>格子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5015"/>
        <location filename="../src/pages.cpp" line="5031"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5016"/>
        <location filename="../src/pages.cpp" line="5032"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5018"/>
        <source>Coordinate</source>
        <translation>坐标</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5019"/>
        <source>Random Fall</source>
        <translation>随机落点</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5020"/>
        <source>Launch All</source>
        <translation>发射全部</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5021"/>
        <source>Launch</source>
        <translation>发射</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5023"/>
        <source>Cannon Launcher</source>
        <translation>加农炮发射器</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5030"/>
        <source>Cob Cannon</source>
        <translation>玉米加农炮</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5030"/>
        <source>in</source>
        <translation>位于</translation>
    </message>
</context>
<context>
    <name>Pt::DocumentPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5208"/>
        <source>&lt;style&gt;a {text-decoration: none; color: blue}&lt;/style&gt;&lt;h2&gt;About&lt;/h2&gt;&lt;p&gt;This software (PvZ Tools) is applicable to Plants vs. Zombies 1.0.0.1051 original English version only (which you can &lt;a href=&quot;https://pvz.lmintlcx.com/download/&quot;&gt;download here&lt;/a&gt;).&lt;/p&gt;&lt;p&gt;Excessive modification or forced use of non-corresponding game versions can easily cause the game to crash, please back up data file before use. All effects caused by using this software are responsibility of user himself.&lt;/p&gt;&lt;p&gt;Some behavior of trainer (finding game progress, modifying memory data, remote injection code, etc.) may be considered dangerous by anti-virus software. Please decide whether to trust this software yourself.&lt;/p&gt;&lt;p&gt;Reasonable uses of trainer include, but not limited to, demonstrations, testing, research, and entertainment. Abuse of modifiers may reduce the fun of game seriously, please use it with caution, especially newbies.&lt;/p&gt;&lt;p&gt;There may be some bugs with this software, users can summit feedback or feature request to the author. The beta version of this software has a time limit, please download latest version if it prompt expires.&lt;/p&gt;&lt;p&gt;Configuration information is saved in &quot;HKEY_CURRENT_USER\SOFTWARE\Cube Studio\PvZ Tools\v2&quot;. You can export this registry item for back up, or clean it after delete this software.&lt;/p&gt;&lt;p&gt;Most important data (memory address) comes from existing public information and other open source modifiers. And source code is copy and paste from Stack Overflow.&lt;/p&gt;&lt;p&gt;All source code is located at &lt;a href=&quot;https://github.com/lmintlcx/pvztools/&quot;&gt;https://github.com/lmintlcx/pvztools/&lt;/a&gt;.&lt;/p&gt;&lt;h2&gt;Spawn&lt;/h2&gt;&lt;p&gt;This feature is suitable for later period of survival endless. Size of zombie&apos;s spawning list is 1000, which is 20 waves per level and 50 zombies per wave.&lt;/p&gt;&lt;p&gt;The spawn page has two modes: &quot;brief&quot; and &quot;detailed&quot;.&lt;/p&gt;&lt;p&gt;When switching between different pages, if the number of zombie types selected on target page is 0, selected zombie types on current page will be synchronized to target page (not one-to-one correspondence).&lt;/p&gt;&lt;p&gt;In brief mode, you can switch layout of the option boxes, in order of zombies in almanac or in same position as the PVZombiesSeed.exe.&lt;/p&gt;&lt;p&gt;In brief mode, Conehead Zombie and Newspaper Zombie are mutually exclusive if &quot;Limit Spawn Count&quot; is checked, and it will limit the number of selected zombie types, up to 10 types except Bungee Zombie and Zombie Yeti. (Note that this limitation is not same as the game itself.)&lt;/p&gt;&lt;p&gt;The difference between different spawn mode:&lt;br&gt;Natural spawn changes the zombie types only and calls built-in function of game to generates zombies list.&lt;br&gt;Extreme spawn is to evenly populate the zombies list with seleted zombie types.&lt;br&gt;Simulate natural spawn is randomly fill the zombies list with seleted zombie types according to certern ratio, meanwhile decrease the probability of GigaGargantuar in non flag wave.&lt;/p&gt;&lt;p&gt;Special deal with some zombies:&lt;br&gt;When limit Flag Zombie, Flag Zombie will only appear in each flag wave (huge wave).&lt;br&gt;When limit Zombie Yeti, there will be only one Zombie Yeti.&lt;br&gt;When limit Bungee Zombie, Bungee Zombie will only appear in flag wave (huge wave).&lt;br&gt;When limit GigaGargantuar, GigaGargantuar will only appear in selected wave(s) (20 waves total).&lt;/p&gt;&lt;p&gt;When using natural spawn in brief mode, there must be Zombie.&lt;/p&gt;&lt;p&gt;When using extreme spawn in brief mode, there must be Zombie and Flag Zombie. Flag Zombie, Zombie Yeti and Bungee Zombie is limited, and GigaGargantuar has no limit.&lt;/p&gt;&lt;p&gt;When using simulate natural spawn in detailed mode, there must be Zombie and Flag Zombie. Flag Zombie, Zombie Yeti and Bungee Zombie is limited.&lt;/p&gt;&lt;h2&gt;Lineup&lt;/h2&gt;&lt;p&gt;Checking &quot;Quick Lineup Mode&quot; will enable these features: Auto Collect, Cob Cannon No CD, Plant Invincible, Stop Spawning, Ignore Sun, Slots No CD, Purple Seed Unlimited, No Fog.&lt;/p&gt;&lt;p&gt;Clicking &quot;Quick Pass&quot; will end current level directly, kill all zombies on the field, set the number of sunshine to 8000, and set the number of levels to 1009 (2020 flags completed). You can modify sunshine and level in corresponding page by pause the game immediately after clicking it.&lt;/p&gt;&lt;p&gt;Format of lineup string is compatible with &lt;a href=&quot;https://pvz.lmintlcx.com/lineup/&quot;&gt;Array Design&lt;/a&gt;.&lt;/p&gt;&lt;p&gt;The built-in lineup string includes some well-known build in &lt;a href=&quot;https://tieba.baidu.com/f?kw=植物大战僵尸&amp;ie=utf-8&amp;tab=good&quot;&gt;good tab&lt;/a&gt; at Baidu Tieba. Players can adjust lineup as needed, don&apos;t have to follow the original array completely.&lt;/p&gt;&lt;p&gt;Clicking &quot;Update&quot; will update built-in array list via Internet. Which is collected by me and will be update if I&apos;m happy.&lt;/p&gt;&lt;p&gt;Modifying game scene may cause some unknown problems, therefore the &quot;Allow Switch Scene&quot; option is not checked by default. It is recommended to enter the hidden scene in a &lt;a href=&quot;https://pvz.lmintlcx.com/pvztoolsdemo/hiddenscene/&quot;&gt;more conventional way&lt;/a&gt; and then mix to &quot;Survival Endless&quot; mode.&lt;/p&gt;&lt;p&gt;When &quot;Keep HP Status&quot; is checked, appearance status of some plants (Wall-nut, Tall-nut, Pumpkin, Garlic, Spikerock) will be preserved when importing or exporting lineup strings.&lt;/p&gt;&lt;h2&gt;Others&lt;/h2&gt;&lt;p&gt;The &quot;Open Data Dir&quot; feature is temporarily unavailable on XP systems (the data file is located in the &quot;userdata&quot; folder in game directory). For Vista and above, it&apos;s located in &quot;C:\ProgramData\PopCap Games\PlantsVsZombies\userdata\&quot; folder.&lt;/p&gt;&lt;p&gt;The unpacked file is located in the specified folder. But the packaged file will be named with &quot;main_&amp;lt;number&amp;gt;.pak&quot;, please rename it to &quot;main.pak&quot; and replace the original game file (remember to backup first).&lt;/p&gt;</source>
        <translation>&lt;style&gt;a {text-decoration: none; color: blue}&lt;/style&gt;
&lt;h2&gt;关于&lt;/h2&gt;
&lt;p&gt;本软件（PvZ Tools）仅适用于植物大战僵尸 1.0.0.1051 英文原版（可从 &lt;a href=&quot;https://pvz.lmintlcx.com/download/&quot;&gt;这里下载&lt;/a&gt;）。&lt;/p&gt;
&lt;p&gt;过度修改或者强行使用不对应的游戏版本很容易造成游戏崩溃，使用前请及时备份存档。对于使用本软件造成的所有影响由用户自己负责。&lt;/p&gt;
&lt;p&gt;修改器的部分行为（查找游戏进程，修改内存数据，远程注入代码等）可能会被杀毒软件视为危险行为，请自行决定是否信任本软件。&lt;/p&gt;
&lt;p&gt;修改器的合理用途包括但不限于演示、测试、研究和娱乐。滥用修改器会严重降低游戏乐趣，新手请慎重使用。&lt;/p&gt;
&lt;p&gt;本软件可能存在一些问题，用户可以向作者提供问题反馈或者功能需求。测试版有使用期限限制，如果提示过期请下载最新版本。&lt;/p&gt;
&lt;p&gt;配置信息保存在“HKEY_CURRENT_USER\SOFTWARE\Cube Studio\PvZ Tools\v2”。你可以导出这个注册表项目来备份，或者在删除本软件后清理它。&lt;/p&gt;
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
&lt;p&gt;点击“快速过关”后会直接结束本关卡，秒杀所有场上僵尸，并将阳光数设置为 8000，关卡数设置为 1009（已完成 2020 面旗帜数）。可以在点击后立即暂停游戏并去对应的页面修改阳光和关卡数。&lt;/p&gt;
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
        <location filename="../src/pages.cpp" line="5241"/>
        <source>Document</source>
        <translation>文档</translation>
    </message>
</context>
<context>
    <name>Pt::EffectPage</name>
    <message>
        <location filename="../src/pages.cpp" line="4184"/>
        <source>Ice Trail Coordinate</source>
        <translation>冰道坐标</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4186"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4188"/>
        <source>Full Fog</source>
        <translation>全屏浓雾</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4189"/>
        <source>No Fog</source>
        <translation>浓雾透视</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4190"/>
        <source>See Vase</source>
        <translation>花瓶透视</translation>
    </message>
</context>
<context>
    <name>Pt::GardenPage</name>
    <message>
        <location filename="../src/pages.cpp" line="3521"/>
        <source>Fertilizer Unlimited</source>
        <translation>花肥无限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3522"/>
        <source>Bug Spray Unlimited</source>
        <translation>杀虫剂无限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3523"/>
        <source>Chocolate Unlimited</source>
        <translation>巧克力无限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3524"/>
        <source>Tree Food Unlimited</source>
        <translation>树肥无限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3526"/>
        <source>Tree Height</source>
        <translation>智慧树高度</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3527"/>
        <location filename="../src/pages.cpp" line="3531"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3529"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3530"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3533"/>
        <source>Scene</source>
        <translation>场地</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3534"/>
        <source>Type</source>
        <translation>类型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3535"/>
        <source>Direction</source>
        <translation>方向</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3536"/>
        <source>Color</source>
        <translation>颜色</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3537"/>
        <source>Status</source>
        <translation>状态</translation>
    </message>
</context>
<context>
    <name>Pt::LevelPage</name>
    <message>
        <location filename="../src/pages.cpp" line="220"/>
        <source>Get Gold Sunflower Trophy</source>
        <translation>解锁金向日葵</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="221"/>
        <source>Get All Shop Items</source>
        <translation>获得商店物品</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="222"/>
        <source>Unlock All Mode Temporarily</source>
        <translation>临时解锁所有模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="223"/>
        <source>Direct Win</source>
        <translation>直接过关</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="225"/>
        <location filename="../src/pages.cpp" line="226"/>
        <location filename="../src/pages.cpp" line="227"/>
        <source>Switch to another game interface (like help) and return to view results after the operation is done.</source>
        <translation>操作完成后切换到其他游戏界面（比如帮助）再返回来查看结果。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="229"/>
        <source>Adventure</source>
        <translation>冒险模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="230"/>
        <source>Mini-Games</source>
        <translation>迷你游戏</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="231"/>
        <source>Puzzle</source>
        <translation>解谜模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="232"/>
        <source>Survival</source>
        <translation>生存模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="267"/>
        <source>Mix Mode</source>
        <translation>混乱</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="269"/>
        <source>Show Hidden Games</source>
        <translation>显示隐藏游戏</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="272"/>
        <source>Lock IZE Array</source>
        <translation>锁定 IZE 阵型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="274"/>
        <source>Jump Level</source>
        <translation>跳关</translation>
    </message>
</context>
<context>
    <name>Pt::LineupPage</name>
    <message>
        <location filename="../src/pages.cpp" line="3266"/>
        <source>Warning</source>
        <translation>警告</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2784"/>
        <location filename="../src/pages.cpp" line="3201"/>
        <source>Wrong string format!</source>
        <translation>字符串格式错误！</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2805"/>
        <source>Already copied.</source>
        <translation>已复制。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2824"/>
        <source>Already pasted.</source>
        <translation>已粘贴。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2838"/>
        <source>Quick Lineup Mode</source>
        <translation>快捷布阵模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2839"/>
        <source>Quick Pass</source>
        <translation>快速过关</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2840"/>
        <source>Mix Mode To Survival Endless</source>
        <translation>混乱到生存无尽</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2842"/>
        <source>Turn on a series of features that are convenient for manual lineup.</source>
        <translation>打开一系列方便手动布阵的功能。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2843"/>
        <source>Kill all zombies and end current level directly with 8000 sunshine and 2020 flags.</source>
        <translation>杀死所有僵尸并用 8000 阳光 2020 面旗帜数直接过关。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2846"/>
        <source>Lily Pad On Pool</source>
        <translation>水路睡莲</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2847"/>
        <source>Flower Pot On Roof</source>
        <translation>屋顶花盆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2848"/>
        <source>Clear All Plants</source>
        <translation>清空植物</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2856"/>
        <source>Open Array Design Page</source>
        <translation>打开网页布阵器</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2857"/>
        <source>Update</source>
        <translation>更新</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3133"/>
        <source>Unable to connect to network.</source>
        <translation>无法连接到网络。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3157"/>
        <source>Update failed, lineup string database parsing error.</source>
        <translation>更新失败，布阵字符串数据库解析出错。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3176"/>
        <source>Lineup string updated, version %1, total %2.</source>
        <translation>阵型字符串已更新，版本 %1，数量 %2。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3180"/>
        <source>Lineup already up to date, version %1, total %2.</source>
        <translation>阵型已是最新，版本 %1，数量 %2。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3186"/>
        <source>Error while connecting to update server.</source>
        <translation>连接到更新服务器时出错。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3233"/>
        <source>Name</source>
        <translation>名称</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3234"/>
        <source>Please input lineup name:</source>
        <translation>请输入阵型名称：</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3244"/>
        <source>Save failed, name cannot contain character &quot;|&quot;.</source>
        <translation>保存失败，名称中不能包含“|”字符。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3255"/>
        <source>Lineup %1 already saved.</source>
        <translation>阵型 %1 已保存。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3267"/>
        <source>Are you sure you want to delete lineup %1?</source>
        <translation>确定要删除阵型 %1 吗？</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3289"/>
        <source>Lineup %1 already deleted.</source>
        <translation>阵型 %1 已删除。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2858"/>
        <source>One Key Setup</source>
        <translation>一键布阵</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2845"/>
        <source>Clear All Graves</source>
        <translation>清空墓碑</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2860"/>
        <source>String -&gt; Lineup</source>
        <translation>字符串 -&gt; 阵型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2861"/>
        <source>String &lt;- Lineup</source>
        <translation>字符串 &lt;- 阵型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2863"/>
        <source>Copy</source>
        <translation>复制</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2864"/>
        <source>Paste</source>
        <translation>粘贴</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2865"/>
        <source>Save</source>
        <translation>保存</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2866"/>
        <source>Delete</source>
        <translation>删除</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2868"/>
        <source>Allow Switch Scene</source>
        <translation>允许切换场地</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2869"/>
        <source>Keep HP Status</source>
        <translation>保留耐久状态</translation>
    </message>
</context>
<context>
    <name>Pt::List</name>
    <message>
        <location filename="../src/list.cpp" line="55"/>
        <source>Level</source>
        <translation>关卡</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="56"/>
        <source>Resources</source>
        <translation>资源</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="57"/>
        <location filename="../src/list.cpp" line="352"/>
        <source>Plants</source>
        <translation>植物</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="58"/>
        <location filename="../src/list.cpp" line="353"/>
        <source>Zombies</source>
        <translation>僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="59"/>
        <source>Spawn</source>
        <translation>出怪</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="60"/>
        <source>Slots</source>
        <translation>卡槽</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="61"/>
        <location filename="../src/list.cpp" line="505"/>
        <source>Scene</source>
        <translation>场地</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="62"/>
        <source>Lineup</source>
        <translation>布阵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="63"/>
        <source>Garden</source>
        <translation>花园</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="64"/>
        <location filename="../src/list.cpp" line="348"/>
        <source>Vase</source>
        <translation>罐子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="65"/>
        <source>Effects</source>
        <translation>特效</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="66"/>
        <source>Others</source>
        <translation>杂项</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="67"/>
        <source>Status</source>
        <translation>状态</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="415"/>
        <source>Peashooter</source>
        <translation>豌豆射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="295"/>
        <location filename="../src/list.cpp" line="421"/>
        <source>Chomper</source>
        <translation>大嘴花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="224"/>
        <location filename="../src/list.cpp" line="294"/>
        <location filename="../src/list.cpp" line="419"/>
        <source>Potato Mine</source>
        <translation>土豆雷</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="436"/>
        <source>Spikeweed</source>
        <translation>地刺</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="444"/>
        <source>Starfruit</source>
        <translation>杨桃</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="425"/>
        <source>Fume-shroom</source>
        <translation>大喷菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="300"/>
        <location filename="../src/list.cpp" line="446"/>
        <source>Magnet-shroom</source>
        <translation>磁力菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="428"/>
        <source>Scaredy-shroom</source>
        <translation>胆小菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="132"/>
        <source>ZomBotany</source>
        <translation>植物僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="133"/>
        <source>Wall-nut Bowling</source>
        <translation>坚果保龄球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="134"/>
        <source>Slot Machine</source>
        <translation>老虎机</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="135"/>
        <source>It&apos;s Raining Seeds</source>
        <translation>雨中种植物</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="136"/>
        <source>Beghouled</source>
        <translation>宝石迷阵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="137"/>
        <source>Invisi-ghoul</source>
        <translation>隐形食脑者</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="138"/>
        <source>Seeing Stars</source>
        <translation>看星星</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="139"/>
        <source>Zombiquarium</source>
        <translation>僵尸水族馆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="140"/>
        <source>Beghouled Twist</source>
        <translation>宝石迷阵转转看</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="141"/>
        <source>Big Trouble Little Zombie</source>
        <translation>小僵尸大麻烦</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="142"/>
        <source>Portal Combat</source>
        <translation>保护传送门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="143"/>
        <source>Column Like You See&apos;Em</source>
        <translation>你看，他们像柱子一样</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="144"/>
        <source>Bobseld Bonanza</source>
        <translation>雪橇区</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="145"/>
        <source>Zombie Nimble Zombie Quick</source>
        <translation>僵尸快跑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="146"/>
        <source>Whack a Zombie</source>
        <translation>锤僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="147"/>
        <source>Last Stand</source>
        <translation>谁笑到最后</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="148"/>
        <source>ZomBotany 2</source>
        <translation>植物僵尸 2</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="149"/>
        <source>Wall-nut Bowling 2</source>
        <translation>坚果保龄球 2</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="150"/>
        <source>Pogo Party</source>
        <translation>跳跳舞会</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="151"/>
        <source>Dr. Zomboss&apos;s Revenge</source>
        <translation>僵王博士的复仇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="152"/>
        <source>Art Challenge Wall-nut</source>
        <translation>坚果艺术</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="153"/>
        <source>Sunny Day</source>
        <translation>晴天</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="154"/>
        <source>Unsodded (FC)</source>
        <translation>无草皮之地（FC）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="155"/>
        <source>Big Time</source>
        <translation>重要时间</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="156"/>
        <source>Art Challenge Sunflower</source>
        <translation>太阳花艺术</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="157"/>
        <source>Air Raid</source>
        <translation>空袭</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="158"/>
        <source>Ice Level</source>
        <translation>冰冻关卡</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="159"/>
        <source>Zen Garden (FC)</source>
        <translation>禅境花园（FC）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="160"/>
        <source>High Gravity</source>
        <translation>超乎寻常的压力</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="161"/>
        <source>Grave Danger</source>
        <translation>坟墓模式</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="162"/>
        <location filename="../src/list.cpp" line="181"/>
        <source>Can You Dig It?</source>
        <translation>你能把它挖出来吗？</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="163"/>
        <source>Dark Stormy Night</source>
        <translation>暴风雨之夜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="164"/>
        <source>Bungee Blitz</source>
        <translation>蹦极闪电战</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="165"/>
        <source>Squirrel</source>
        <translation>松鼠</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="166"/>
        <location filename="../src/list.cpp" line="326"/>
        <source>Tree of Wisdom</source>
        <translation>智慧树</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="169"/>
        <source>Vasebreaker</source>
        <translation>破罐者</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="170"/>
        <source>To the Left</source>
        <translation>一路向左</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="171"/>
        <source>Third Vase</source>
        <translation>第三个罐子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="172"/>
        <source>Chain Reaction</source>
        <translation>连锁反应</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="173"/>
        <source>M is for Metal</source>
        <translation>M 的意思是金属</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="174"/>
        <source>Scary Potter</source>
        <translation>胆怯的制陶工</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="175"/>
        <source>Hokey Pokey</source>
        <translation>变戏法</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="176"/>
        <source>Another Chain Reaction</source>
        <translation>另一个连锁反应</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="177"/>
        <source>Ace of Vase</source>
        <translation>罐子王牌</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="178"/>
        <source>Vasebreaker Endless</source>
        <translation>无尽的试炼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="179"/>
        <source>I, Zombie</source>
        <translation>我是僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="180"/>
        <source>I, Zombie Too</source>
        <translation>我也是僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="182"/>
        <source>Totally Nuts</source>
        <translation>完全傻了</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="183"/>
        <source>Dead Zeppelin</source>
        <translation>死亡飞艇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="184"/>
        <source>Me Smash!</source>
        <translation>我烂了！</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="185"/>
        <source>ZomBoogie</source>
        <translation>僵尸摇摆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="186"/>
        <source>Three Hit Wonder</source>
        <translation>三连击</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="187"/>
        <source>All your brainz r belong to us</source>
        <translation>你所有大脑都是属于我的</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="188"/>
        <source>I, Zombie Endless</source>
        <translation>我是僵尸无尽版</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="189"/>
        <source>Upsell</source>
        <translation>追加销售</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="190"/>
        <source>Intro</source>
        <translation>介绍</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="193"/>
        <source>Survival: Day</source>
        <translation>生存模式：白天</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="194"/>
        <source>Survival: Night</source>
        <translation>生存模式：黑夜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="195"/>
        <source>Survival: Pool</source>
        <translation>生存模式：泳池</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="196"/>
        <source>Survival: Fog</source>
        <translation>生存模式：浓雾</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="197"/>
        <source>Survival: Roof</source>
        <translation>生存模式：屋顶</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="198"/>
        <source>Survival: Day (Hard)</source>
        <translation>生存模式：白天（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="199"/>
        <source>Survival: Night (Hard)</source>
        <translation>生存模式：黑夜（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="200"/>
        <source>Survival: Pool (Hard)</source>
        <translation>生存模式：泳池（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="201"/>
        <source>Survival: Fog (Hard)</source>
        <translation>生存模式：浓雾（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="202"/>
        <source>Survival: Roof (Hard)</source>
        <translation>生存模式：屋顶（困难）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="203"/>
        <source>Survival: Day (Endless)</source>
        <translation>生存模式：白天（无尽版）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="204"/>
        <source>Survival: Night (Endless)</source>
        <translation>生存模式：黑夜（无尽版）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="205"/>
        <source>Survival: Endless</source>
        <translation>生存模式：无尽版</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="206"/>
        <source>Survival: Fog (Endless)</source>
        <translation>生存模式：浓雾（无尽版）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="207"/>
        <source>Survival: Roof (Endless)</source>
        <translation>生存模式：屋顶（无尽版）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="210"/>
        <source>Pea</source>
        <translation>豌豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="211"/>
        <source>Frozen Pea</source>
        <translation>冰豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="212"/>
        <source>Cabbage</source>
        <translation>卷心菜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="213"/>
        <source>Melon</source>
        <translation>西瓜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="214"/>
        <source>Fume</source>
        <translation>烟雾</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="215"/>
        <location filename="../src/list.cpp" line="459"/>
        <source>Winter Melon</source>
        <translation>冰瓜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="216"/>
        <source>Fireball</source>
        <translation>火球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="217"/>
        <source>Star</source>
        <translation>星星</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="218"/>
        <source>Spike</source>
        <translation>尖刺</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="219"/>
        <source>Basketball</source>
        <translation>篮球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="220"/>
        <source>Kernel</source>
        <translation>玉米</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="221"/>
        <source>Butter</source>
        <translation>黄油</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="222"/>
        <source>Zombie Pea</source>
        <translation>僵尸豌豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="223"/>
        <source>Ash</source>
        <translation>灰烬</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="225"/>
        <location filename="../src/list.cpp" line="297"/>
        <location filename="../src/list.cpp" line="429"/>
        <source>Ice-shroom</source>
        <translation>寒冰菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="226"/>
        <location filename="../src/list.cpp" line="432"/>
        <source>Squash</source>
        <translation>倭瓜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="227"/>
        <source>Bite</source>
        <translation>啃咬</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="231"/>
        <location filename="../src/list.cpp" line="418"/>
        <source>Wall-nut</source>
        <translation>坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="232"/>
        <location filename="../src/list.cpp" line="438"/>
        <source>Tall-nut</source>
        <translation>高坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="233"/>
        <location filename="../src/list.cpp" line="445"/>
        <source>Pumpkin</source>
        <translation>南瓜头</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="234"/>
        <location filename="../src/list.cpp" line="451"/>
        <source>Garlic</source>
        <translation>大蒜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="235"/>
        <location filename="../src/list.cpp" line="461"/>
        <source>Spikerock</source>
        <translation>地刺王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="237"/>
        <location filename="../src/list.cpp" line="476"/>
        <source>Conehead Zombie</source>
        <translation>路障</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="238"/>
        <location filename="../src/list.cpp" line="477"/>
        <source>Pole Vaulting Zombie</source>
        <translation>撑杆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="239"/>
        <location filename="../src/list.cpp" line="478"/>
        <source>Buckethead Zombie</source>
        <translation>铁桶</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="240"/>
        <source>Newspaper Zombie</source>
        <translation>读报</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="241"/>
        <location filename="../src/list.cpp" line="484"/>
        <source>Screen Door Zombie</source>
        <translation>铁门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="242"/>
        <location filename="../src/list.cpp" line="482"/>
        <source>Football Zombie</source>
        <translation>橄榄</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="243"/>
        <location filename="../src/list.cpp" line="487"/>
        <source>Dancing Zombie</source>
        <translation>舞王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="244"/>
        <location filename="../src/list.cpp" line="485"/>
        <source>Zomboni</source>
        <translation>冰车</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="245"/>
        <source>Dolphin Rider Zombie</source>
        <translation>海豚</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="246"/>
        <source>Jack-in-the-Box Zombie</source>
        <translation>小丑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="247"/>
        <location filename="../src/list.cpp" line="480"/>
        <source>Digger Zombie</source>
        <translation>矿工</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="248"/>
        <location filename="../src/list.cpp" line="486"/>
        <source>Pogo Zombie</source>
        <translation>跳跳</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="249"/>
        <source>Zombie Yeti</source>
        <translation>雪人</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="250"/>
        <location filename="../src/list.cpp" line="481"/>
        <source>Bungee Zombie</source>
        <translation>蹦极</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="251"/>
        <location filename="../src/list.cpp" line="479"/>
        <source>Ladder Zombie</source>
        <translation>扶梯</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="252"/>
        <location filename="../src/list.cpp" line="488"/>
        <source>Gargantuar</source>
        <translation>白眼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="253"/>
        <source>Dr. Zomboss</source>
        <translation>僵王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="254"/>
        <source>Dr. Zomboss Extra</source>
        <translation>僵王附加</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="255"/>
        <source>Wall-nut Zombie</source>
        <translation>坚果僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="256"/>
        <source>Jalapeno Zombie</source>
        <translation>辣椒僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="257"/>
        <source>Tall-nut Zombie</source>
        <translation>高坚果僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="258"/>
        <source>GigaGargantuar</source>
        <translation>红眼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="259"/>
        <source>Imp in I, Zombie</source>
        <translation>我是僵尸小鬼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="260"/>
        <source>Balloon</source>
        <translation>气球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="263"/>
        <source>Silver Coin</source>
        <translation>银币</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="264"/>
        <source>Gold Coin</source>
        <translation>金币</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="265"/>
        <source>Diamond</source>
        <translation>钻石</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="266"/>
        <location filename="../src/list.cpp" line="560"/>
        <source>Sun</source>
        <translation>阳光</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="267"/>
        <source>Small Sun</source>
        <translation>小阳光</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="268"/>
        <source>Big Sun</source>
        <translation>大阳光</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="292"/>
        <source>Fog Clear</source>
        <translation>浓雾退散</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="293"/>
        <source>Cherry Bomb / Jalapeno</source>
        <translation>樱桃/辣椒</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="296"/>
        <location filename="../src/list.cpp" line="424"/>
        <source>Sun-shroom</source>
        <translation>阳光菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="298"/>
        <location filename="../src/list.cpp" line="430"/>
        <source>Doom-shroom</source>
        <translation>毁灭菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="299"/>
        <location filename="../src/list.cpp" line="442"/>
        <source>Blover</source>
        <translation>三叶草</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="301"/>
        <source>Cob Cannon Filling</source>
        <translation>玉米炮装填</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="302"/>
        <source>Backup Dancer Call</source>
        <translation>召唤伴舞</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="303"/>
        <source>Zombie Yeti Run Away</source>
        <translation>雪人逃跑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="304"/>
        <source>Bungee Zombie Stay</source>
        <translation>蹦极停留</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="307"/>
        <source>Lawn</source>
        <translation>草地</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="308"/>
        <source>Bare</source>
        <translation>裸地</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="309"/>
        <location filename="../src/list.cpp" line="319"/>
        <source>Pool</source>
        <translation>泳池</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="312"/>
        <location filename="../src/list.cpp" line="551"/>
        <source>None</source>
        <translation>无</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="313"/>
        <source>Land</source>
        <translation>陆路</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="314"/>
        <source>Water</source>
        <translation>水路</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="317"/>
        <source>Day</source>
        <translation>白天</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="318"/>
        <source>Night</source>
        <translation>黑夜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="320"/>
        <source>Fog</source>
        <translation>浓雾</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="321"/>
        <source>Roof</source>
        <translation>屋顶</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="322"/>
        <source>Moon</source>
        <translation>月夜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="323"/>
        <location filename="../src/list.cpp" line="513"/>
        <source>Mushroom Garden</source>
        <translation>蘑菇园</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="324"/>
        <location filename="../src/list.cpp" line="512"/>
        <source>Zen Garden</source>
        <translation>禅境花园</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="325"/>
        <location filename="../src/list.cpp" line="515"/>
        <source>Aquarium Garden</source>
        <translation>水族馆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="343"/>
        <source>Grave</source>
        <translation>墓碑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="344"/>
        <source>Crater</source>
        <translation>弹坑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="345"/>
        <source>Ladder</source>
        <translation>梯子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="346"/>
        <source>White Portal</source>
        <translation>白传送门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="347"/>
        <source>Black Portal</source>
        <translation>黑传送门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="349"/>
        <source>Snail</source>
        <translation>蜗牛</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="350"/>
        <source>Rake</source>
        <translation>钉耙</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="351"/>
        <source>Brain</source>
        <translation>脑子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="356"/>
        <source>Kill</source>
        <translation>秒杀</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="357"/>
        <source>Hypno</source>
        <translation>魅惑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="358"/>
        <source>Freeze</source>
        <translation>冻结</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="359"/>
        <source>Decelerate</source>
        <translation>减速</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="360"/>
        <source>Immobilize</source>
        <translation>固定</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="361"/>
        <source>Blow Away</source>
        <translation>吹走</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="362"/>
        <source>Dying</source>
        <translation>濒死</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="363"/>
        <source>Disappear</source>
        <translation>消失</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="364"/>
        <source>Black</source>
        <translation>变黑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="365"/>
        <source>Bigger</source>
        <translation>变大</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="368"/>
        <source>Zombie</source>
        <comment>Zombie</comment>
        <translation>普僵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="369"/>
        <source>Flag Zombie</source>
        <comment>Zombie</comment>
        <translation>旗帜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="370"/>
        <source>Conehead Zombie</source>
        <comment>Zombie</comment>
        <translation>路障</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="371"/>
        <source>Pole Vaulting Zombie</source>
        <comment>Zombie</comment>
        <translation>撑杆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="372"/>
        <source>Buckethead Zombie</source>
        <comment>Zombie</comment>
        <translation>铁桶</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="373"/>
        <source>Newspaper Zombie</source>
        <comment>Zombie</comment>
        <translation>读报</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="374"/>
        <source>Screen Door Zombie</source>
        <comment>Zombie</comment>
        <translation>铁门</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="375"/>
        <source>Football Zombie</source>
        <comment>Zombie</comment>
        <translation>橄榄</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="376"/>
        <source>Dancing Zombie</source>
        <comment>Zombie</comment>
        <translation>舞王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="377"/>
        <source>Backup Dancer</source>
        <comment>Zombie</comment>
        <translation>伴舞</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="378"/>
        <source>Ducky Tube Zombie</source>
        <comment>Zombie</comment>
        <translation>鸭子</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="379"/>
        <source>Snorkel Zombie</source>
        <comment>Zombie</comment>
        <translation>潜水</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="380"/>
        <source>Zomboni</source>
        <comment>Zombie</comment>
        <translation>冰车</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="381"/>
        <source>Zombie Bobsled Team</source>
        <comment>Zombie</comment>
        <translation>雪橇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="382"/>
        <source>Dolphin Rider Zombie</source>
        <comment>Zombie</comment>
        <translation>海豚</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="383"/>
        <source>Jack-in-the-Box Zombie</source>
        <comment>Zombie</comment>
        <translation>小丑</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="384"/>
        <source>Balloon Zombie</source>
        <comment>Zombie</comment>
        <translation>气球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="385"/>
        <source>Digger Zombie</source>
        <comment>Zombie</comment>
        <translation>矿工</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="386"/>
        <source>Pogo Zombie</source>
        <comment>Zombie</comment>
        <translation>跳跳</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="387"/>
        <source>Zombie Yeti</source>
        <comment>Zombie</comment>
        <translation>雪人</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="388"/>
        <source>Bungee Zombie</source>
        <comment>Zombie</comment>
        <translation>蹦极</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="389"/>
        <source>Ladder Zombie</source>
        <comment>Zombie</comment>
        <translation>扶梯</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="390"/>
        <source>Catapult Zombie</source>
        <comment>Zombie</comment>
        <translation>投篮</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="391"/>
        <source>Gargantuar</source>
        <comment>Zombie</comment>
        <translation>白眼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="392"/>
        <source>Imp</source>
        <comment>Zombie</comment>
        <translation>小鬼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="393"/>
        <source>Dr. Zomboss</source>
        <comment>Zombie</comment>
        <translation>僵王</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="394"/>
        <source>Peashooter Zombie</source>
        <comment>Zombie</comment>
        <translation>豌豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="395"/>
        <source>Wall-nut Zombie</source>
        <comment>Zombie</comment>
        <translation>坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="396"/>
        <source>Jalapeno Zombie</source>
        <comment>Zombie</comment>
        <translation>辣椒</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="397"/>
        <source>Gatling Pea Zombie</source>
        <comment>Zombie</comment>
        <translation>机枪</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="398"/>
        <source>Squash Zombie</source>
        <comment>Zombie</comment>
        <translation>倭瓜</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="399"/>
        <source>Tall-nut Zombie</source>
        <comment>Zombie</comment>
        <translation>高坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="400"/>
        <source>GigaGargantuar</source>
        <comment>Zombie</comment>
        <translation>红眼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="554"/>
        <location filename="../src/list.cpp" line="559"/>
        <source>Zombie</source>
        <translation>僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="230"/>
        <source>Plant</source>
        <comment>Normal Plant</comment>
        <translation>普通植物</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="236"/>
        <source>Zombie</source>
        <comment>Normal Zombie</comment>
        <translation>普通僵尸</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="475"/>
        <source>Zombie</source>
        <comment>Zombie Zombie</comment>
        <translation>普僵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="473"/>
        <source>Snorkel Zombie</source>
        <translation>潜水</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="483"/>
        <source>Balloon Zombie</source>
        <translation>气球</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="489"/>
        <source>Imp</source>
        <translation>小鬼</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="403"/>
        <source>1st slot</source>
        <translation>第一格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="404"/>
        <source>2nd slot</source>
        <translation>第二格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="405"/>
        <source>3rd slot</source>
        <translation>第三格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="406"/>
        <source>4th slot</source>
        <translation>第四格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="407"/>
        <source>5th slot</source>
        <translation>第五格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="408"/>
        <source>6th slot</source>
        <translation>第六格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="409"/>
        <source>7th slot</source>
        <translation>第七格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="410"/>
        <source>8th slot</source>
        <translation>第八格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="411"/>
        <source>9th slot</source>
        <translation>第九格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="412"/>
        <source>10th slot</source>
        <translation>第十格</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="416"/>
        <source>Sunflower</source>
        <translation>向日葵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="417"/>
        <source>Cherry Bomb</source>
        <translation>樱桃炸弹</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="420"/>
        <source>Snow Pea</source>
        <translation>寒冰射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="422"/>
        <source>Repeater</source>
        <translation>双发射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="423"/>
        <source>Puff-shroom</source>
        <translation>小喷菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="426"/>
        <source>Grave Buster</source>
        <translation>墓碑吞噬者</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="427"/>
        <source>Hypno-shroom</source>
        <translation>魅惑菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="431"/>
        <source>Lily Pad</source>
        <translation>睡莲</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="433"/>
        <source>Threepeater</source>
        <translation>三线射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="434"/>
        <source>Tangle Kelp</source>
        <translation>缠绕海草</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="435"/>
        <source>Jalapeno</source>
        <translation>火爆辣椒</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="437"/>
        <source>Torchwood</source>
        <translation>火炬树桩</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="439"/>
        <source>Sea-shroom</source>
        <translation>海蘑菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="440"/>
        <source>Plantern</source>
        <translation>路灯花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="441"/>
        <source>Cactus</source>
        <translation>仙人掌</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="443"/>
        <source>Split Pea</source>
        <translation>裂荚射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="447"/>
        <source>Cabbage-pult</source>
        <translation>卷心菜投手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="448"/>
        <source>Flower Pot</source>
        <translation>花盆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="449"/>
        <source>Kernel-pult</source>
        <translation>玉米投手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="450"/>
        <source>Coffee Bean</source>
        <translation>咖啡豆</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="452"/>
        <source>Umbrella Leaf</source>
        <translation>叶子保护伞</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="453"/>
        <source>Marigold</source>
        <translation>金盏花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="454"/>
        <source>Melon-pult</source>
        <translation>西瓜投手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="455"/>
        <source>Gatling Pea</source>
        <translation>机枪射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="456"/>
        <source>Twin Sunflower</source>
        <translation>双子向日葵</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="457"/>
        <source>Gloom-shroom</source>
        <translation>忧郁蘑菇</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="458"/>
        <source>Cattail</source>
        <translation>香蒲</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="460"/>
        <source>Gold Magnet</source>
        <translation>吸金磁</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="462"/>
        <source>Cob Cannon</source>
        <translation>玉米加农炮</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="463"/>
        <location filename="../src/list.cpp" line="523"/>
        <source>Imitater</source>
        <translation>模仿者</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="464"/>
        <source>Explode-o-nut</source>
        <translation>爆炸坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="465"/>
        <source>Giant Wall-nut</source>
        <translation>巨大坚果</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="466"/>
        <location filename="../src/list.cpp" line="537"/>
        <source>Sprout</source>
        <translation>幼苗</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="467"/>
        <source>Reverse Repeater</source>
        <translation>左向双发射手</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="468"/>
        <source>Nothing (FC)</source>
        <translation>无（FC）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="469"/>
        <source>Shuffle plant (FC)</source>
        <translation>转向（FC）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="470"/>
        <source>Refill crator (FC)</source>
        <translation>消除弹坑（FC）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="471"/>
        <source>Sun (FC)</source>
        <translation>阳光（FC）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="472"/>
        <source>Diamond (FC)</source>
        <translation>钻石（FC）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="474"/>
        <source>Trophy</source>
        <translation>奖杯</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="490"/>
        <source>&lt;Missing&gt; (FC)</source>
        <translation>&lt;消失&gt;（FC）</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="493"/>
        <source>All Rows</source>
        <translation>所有行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="494"/>
        <source>1st Row</source>
        <translation>第一行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="495"/>
        <source>2nd Row</source>
        <translation>第二行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="496"/>
        <source>3rd Row</source>
        <translation>第三行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="497"/>
        <source>4th Row</source>
        <translation>第四行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="498"/>
        <source>5th Row</source>
        <translation>第五行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="499"/>
        <source>6th Row</source>
        <translation>第六行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="502"/>
        <location filename="../src/list.cpp" line="543"/>
        <source>Index</source>
        <translation>序号</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="503"/>
        <location filename="../src/list.cpp" line="544"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="504"/>
        <location filename="../src/list.cpp" line="545"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="506"/>
        <location filename="../src/list.cpp" line="547"/>
        <source>Type</source>
        <translation>类型</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="507"/>
        <source>Direction</source>
        <translation>方向</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="508"/>
        <source>Color</source>
        <translation>颜色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="509"/>
        <source>Status</source>
        <comment>grow up status</comment>
        <translation>状态</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="514"/>
        <source>Wheel Barrow</source>
        <translation>手推车</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="518"/>
        <source>Right</source>
        <translation>右</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="519"/>
        <source>Left</source>
        <translation>左</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="522"/>
        <source>Original</source>
        <translation>原色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="524"/>
        <source>White</source>
        <translation>白色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="525"/>
        <source>Magenta</source>
        <translation>品红色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="526"/>
        <source>Orange</source>
        <translation>橙色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="527"/>
        <source>Pink</source>
        <translation>粉红色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="528"/>
        <source>Cyan</source>
        <translation>青色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="529"/>
        <source>Red</source>
        <translation>红色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="530"/>
        <source>Blue</source>
        <translation>蓝色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="531"/>
        <source>Purple</source>
        <translation>紫色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="532"/>
        <source>Lavender</source>
        <translation>淡紫色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="533"/>
        <source>Yellow</source>
        <translation>黄色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="534"/>
        <source>LightGreen</source>
        <translation>浅绿色</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="538"/>
        <source>Small Size</source>
        <translation>小花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="539"/>
        <source>Medium Size</source>
        <translation>中花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="540"/>
        <source>Full Size</source>
        <translation>大花</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="546"/>
        <source>Skin</source>
        <translation>皮肤</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="548"/>
        <source>Content</source>
        <translation>内容</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="552"/>
        <source>Unknown</source>
        <translation>未知</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="553"/>
        <location filename="../src/list.cpp" line="558"/>
        <source>Plant</source>
        <translation>植物</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="557"/>
        <source>Empty</source>
        <translation>空</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="563"/>
        <source>Off</source>
        <translation>关闭</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="564"/>
        <source>Spawning</source>
        <translation>出怪</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="565"/>
        <source>Music</source>
        <translation>音乐</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="566"/>
        <source>Memory</source>
        <translation>内存</translation>
    </message>
    <message>
        <location filename="../src/list.cpp" line="567"/>
        <source>Collision</source>
        <translation>碰撞</translation>
    </message>
</context>
<context>
    <name>Pt::MainWindow</name>
    <message>
        <location filename="../src/window.cpp" line="134"/>
        <location filename="../src/window.cpp" line="136"/>
        <source>Plants vs. Zombies 1.0.0.1051 Toolset</source>
        <translation>植物大战僵尸 1.0.0.1051 辅助工具</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="516"/>
        <location filename="../src/window.cpp" line="531"/>
        <location filename="../src/window.cpp" line="539"/>
        <location filename="../src/window.cpp" line="544"/>
        <source>Update Check</source>
        <translation>更新检查</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="516"/>
        <source>Unable to connect to network.</source>
        <translation>无法连接到网络。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="532"/>
        <source>New version detected, download it now?</source>
        <translation>检测到新版本，现在下载吗？</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="539"/>
        <source>This is already the latest release version.</source>
        <translation>已经是最新版。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="544"/>
        <source>Error while connecting to update server.</source>
        <translation>连接到更新服务器时出错。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="583"/>
        <source>Version</source>
        <translation>版本号</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="584"/>
        <source>Date</source>
        <translation>日期</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="585"/>
        <source>Toolchain</source>
        <translation>工具链</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="587"/>
        <source>Copyright</source>
        <translation>版权所有</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="588"/>
        <source>Credit</source>
        <translation>鸣谢</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="591"/>
        <source>About</source>
        <translation>关于</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="596"/>
        <source>&lt;h1&gt;PvZ Tools&lt;/h1&gt;</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1548"/>
        <source>Open File</source>
        <translation>打开文件</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1549"/>
        <source>Open Folder</source>
        <translation>打开目录</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1550"/>
        <source>Restart</source>
        <translation>重启</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1551"/>
        <source>Exit</source>
        <translation>退出</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1553"/>
        <source>Find Game Again</source>
        <translation>重新查找游戏</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1554"/>
        <source>Game Window Top Most</source>
        <translation>游戏窗口置顶</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1555"/>
        <source>Keep Selected Features</source>
        <translation>维持已选功能</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1570"/>
        <source>Spawning Counting</source>
        <translation>出怪数量统计</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1571"/>
        <source>Target Map Modify</source>
        <translation>目标地图修改</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1572"/>
        <source>Cannon Launcher</source>
        <translation>加农炮发射器</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1573"/>
        <source>Portal</source>
        <translation>传送门</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1575"/>
        <source>Show Sidebar</source>
        <translation>显示侧边栏</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1576"/>
        <source>Switch Spawn Layout</source>
        <translation>小王子出怪器布局</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1577"/>
        <source>Limit Spawn Species</source>
        <translation>限制出怪种类数</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1578"/>
        <source>Save Selected Species</source>
        <translation>保存已选出怪</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1579"/>
        <source>Mute</source>
        <translation>静音</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1580"/>
        <source>Font</source>
        <translation>字体</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1581"/>
        <source>Restore Default Setting</source>
        <translation>恢复默认设置</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1586"/>
        <source>Help Document</source>
        <translation>帮助文档</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1587"/>
        <source>Video Demo</source>
        <translation>视频演示</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1588"/>
        <source>Visit Website</source>
        <translation>访问网站</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1589"/>
        <source>Send Feedback</source>
        <translation>发送反馈</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1590"/>
        <source>Change Log</source>
        <translation>更新日志</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1591"/>
        <source>Check Update</source>
        <translation>检查更新</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1592"/>
        <source>About PvZ Tools</source>
        <translation>关于 PvZ Tools</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1593"/>
        <source>About Qt</source>
        <translation>关于 Qt</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1595"/>
        <source>&amp;File</source>
        <translation>文件(&amp;F)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1596"/>
        <source>&amp;Game</source>
        <translation>游戏(&amp;G)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1597"/>
        <source>&amp;Page</source>
        <translation>页面(&amp;P)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1598"/>
        <source>&amp;Setting</source>
        <translation>设置(&amp;S)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1599"/>
        <source>&amp;Language</source>
        <translation>语言(&amp;L)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1600"/>
        <source>&amp;Help</source>
        <translation>帮助(&amp;H)</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1602"/>
        <source>Page</source>
        <translation>页面</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1609"/>
        <source>Game Found.</source>
        <translation>已找到游戏。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1629"/>
        <source>Unsupported game version.</source>
        <translation>不支持的游戏版本。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1634"/>
        <source>Game window not found.</source>
        <translation>未找到游戏窗口。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1639"/>
        <source>Open game process error.</source>
        <translation>打开游戏进程出错。</translation>
    </message>
    <message>
        <location filename="../src/window.cpp" line="1715"/>
        <source>Message</source>
        <translation>信息</translation>
    </message>
</context>
<context>
    <name>Pt::OthersPage</name>
    <message>
        <location filename="../src/pages.cpp" line="4375"/>
        <source>Disable Save Data</source>
        <translation>禁止存档</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4376"/>
        <source>Disable Delete Data</source>
        <translation>禁止删档</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4378"/>
        <source>Running In Background</source>
        <translation>后台运行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4379"/>
        <source>Disable Pause</source>
        <translation>禁用暂停</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4381"/>
        <source>Open Data Dir</source>
        <translation>打开存档目录</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4383"/>
        <source>Debug Mode</source>
        <translation>调试模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4385"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4387"/>
        <location filename="../src/pages.cpp" line="4402"/>
        <source>Open File</source>
        <translation>打开文件</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4388"/>
        <source>Unpack</source>
        <translation>解包</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4390"/>
        <location filename="../src/pages.cpp" line="4416"/>
        <source>Open Folder</source>
        <translation>打开目录</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4391"/>
        <source>Pack</source>
        <translation>打包</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4393"/>
        <source>Target Map Modify</source>
        <translation>目标地图修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4394"/>
        <source>Cannon Launcher</source>
        <translation>加农炮发射器</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4395"/>
        <source>Portal</source>
        <translation>传送门</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4404"/>
        <source>PAK files (*.pak) ;; All files (*.*)</source>
        <translation>PAK 文件 (*.pak) ;; 所有文件 (*.*)</translation>
    </message>
</context>
<context>
    <name>Pt::PAK</name>
    <message>
        <location filename="../src/pak.cpp" line="508"/>
        <source>Unpack pak Succeeded!</source>
        <translation>解包 pak 成功！</translation>
    </message>
    <message>
        <location filename="../src/pak.cpp" line="512"/>
        <source>Unpack pak Failed!</source>
        <translation>解包 pak 失败！</translation>
    </message>
    <message>
        <location filename="../src/pak.cpp" line="525"/>
        <source>Pack pak Succeeded! File name: &quot;%1&quot;.</source>
        <translation>打包 pak 成功！文件名：“%1”。</translation>
    </message>
    <message>
        <location filename="../src/pak.cpp" line="529"/>
        <source>Pack pak Failed!</source>
        <translation>打包 pak 失败！</translation>
    </message>
</context>
<context>
    <name>Pt::PlantsPage</name>
    <message>
        <location filename="../src/pages.cpp" line="851"/>
        <source>Cob Cannon NoCD</source>
        <translation>玉米炮无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="852"/>
        <source>Magnets NoCD</source>
        <translation>磁力菇无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="853"/>
        <source>Potato Mine NoCD</source>
        <translation>土豆雷无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="854"/>
        <source>Chomper NoCD</source>
        <translation>大嘴花无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="856"/>
        <source>Plant Invincible</source>
        <translation>植物无敌</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="857"/>
        <source>Plant Weak</source>
        <translation>植物脆弱</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="858"/>
        <source>Lock Kernel</source>
        <translation>锁定玉米</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="859"/>
        <source>Lock Butter</source>
        <translation>锁定黄油</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="861"/>
        <source>No Crater</source>
        <translation>不留弹坑</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="862"/>
        <source>Mushrooms Awake</source>
        <translation>蘑菇免唤醒</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="863"/>
        <source>Strong Blover</source>
        <translation>强力三叶草</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="864"/>
        <source>Strong Peas</source>
        <translation>强力豌豆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="866"/>
        <source>Explode Immediately</source>
        <translation>灰烬瞬爆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="867"/>
        <source>Explode Never</source>
        <translation>灰烬不爆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="868"/>
        <source>Beghouled Free Move</source>
        <translation>宝石自由移动</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="869"/>
        <source>Attack Superposition</source>
        <translation>攻击重叠</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="871"/>
        <source>Plant Torchwood</source>
        <translation>植物火炬</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="872"/>
        <source>Plant Garlic</source>
        <translation>植物大蒜</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="873"/>
        <source>Plant Umbrella</source>
        <translation>植物保护伞</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="874"/>
        <source>Plant Paper</source>
        <translation>植物纸板</translation>
    </message>
</context>
<context>
    <name>Pt::PortalPage</name>
    <message>
        <location filename="../src/pages.cpp" line="5175"/>
        <location filename="../src/pages.cpp" line="5177"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5176"/>
        <location filename="../src/pages.cpp" line="5178"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5179"/>
        <source>Black1</source>
        <translation>黑1</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5180"/>
        <source>Black2</source>
        <translation>黑2</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5181"/>
        <source>White1</source>
        <translation>白1</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5182"/>
        <source>White2</source>
        <translation>白2</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5184"/>
        <source>Start</source>
        <translation>启动</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5185"/>
        <source>Lock</source>
        <translation>锁定</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5186"/>
        <source>Set Portal</source>
        <translation>设置传送门</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="5188"/>
        <source>Portal</source>
        <translation>传送门</translation>
    </message>
</context>
<context>
    <name>Pt::PvZ</name>
    <message>
        <location filename="../src/pvz.cpp" line="268"/>
        <source>Already unlocked golden sunflower trophy.</source>
        <translation>已经解锁金向日葵奖杯。</translation>
    </message>
    <message>
        <location filename="../src/pvz.cpp" line="314"/>
        <source>Already get all shop items.</source>
        <translation>已经得到所有商店物品。</translation>
    </message>
    <message>
        <location filename="../src/pvz.cpp" line="2760"/>
        <location filename="../src/pvz.cpp" line="3049"/>
        <source>The current mode is not &apos;Survival: Endless&apos; or &apos;I, Zombie&apos;.</source>
        <translation>当前模式不是“生存无尽”或者“我是僵尸”。</translation>
    </message>
    <message>
        <location filename="../src/pvz.cpp" line="2778"/>
        <location filename="../src/pvz.cpp" line="3055"/>
        <source>The target lineup scene is inconsistent with the current scene.</source>
        <translation>目标阵型场地和当前场地不一致。</translation>
    </message>
</context>
<context>
    <name>Pt::ResourcePage</name>
    <message>
        <location filename="../src/pages.cpp" line="485"/>
        <location filename="../src/pages.cpp" line="487"/>
        <location filename="../src/pages.cpp" line="489"/>
        <location filename="../src/pages.cpp" line="491"/>
        <location filename="../src/pages.cpp" line="591"/>
        <source>Value</source>
        <translation>价值</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="514"/>
        <location filename="../src/pages.cpp" line="516"/>
        <location filename="../src/pages.cpp" line="595"/>
        <source>Damage</source>
        <translation>伤害</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="545"/>
        <location filename="../src/pages.cpp" line="547"/>
        <location filename="../src/pages.cpp" line="599"/>
        <source>HP</source>
        <translation>血量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="545"/>
        <source>Accessories</source>
        <translation>饰品</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="572"/>
        <source>Sun</source>
        <translation>阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="573"/>
        <location filename="../src/pages.cpp" line="576"/>
        <location filename="../src/pages.cpp" line="579"/>
        <location filename="../src/pages.cpp" line="582"/>
        <location filename="../src/pages.cpp" line="593"/>
        <location filename="../src/pages.cpp" line="597"/>
        <location filename="../src/pages.cpp" line="601"/>
        <location filename="../src/pages.cpp" line="605"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="575"/>
        <source>Sun Limit</source>
        <translation>阳光上限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="578"/>
        <source>Money</source>
        <translation>金钱</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="581"/>
        <source>Money Limit</source>
        <translation>金钱上限</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="584"/>
        <source>Many Falling Sun</source>
        <translation>狂掉阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="585"/>
        <source>No Falling Sun</source>
        <translation>不掉阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="586"/>
        <source>Auto Collect</source>
        <translation>自动收集</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="587"/>
        <source>Zombie No Falling</source>
        <translation>僵尸不掉钱</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="589"/>
        <source>This feature is available when &quot;Auto Collect&quot; is turned on.</source>
        <translation>这个功能只有在“自动收集”打开时可用。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="603"/>
        <source>Time</source>
        <translation>时间</translation>
    </message>
</context>
<context>
    <name>Pt::ScenePage</name>
    <message>
        <location filename="../src/pages.cpp" line="2500"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2501"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2511"/>
        <source>Planting</source>
        <translation>种植</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2512"/>
        <source>Imitater</source>
        <translation>模仿者</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2522"/>
        <source>Put</source>
        <translation>放置</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2524"/>
        <source>Grave</source>
        <translation>墓碑</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2525"/>
        <source>Rake</source>
        <translation>钉耙</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2527"/>
        <source>Coin</source>
        <translation>物品</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2528"/>
        <source>Ladder</source>
        <translation>梯子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2529"/>
        <source>Ladder Pumpkin</source>
        <translation>南瓜梯子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2530"/>
        <source>Imitater Pumpkin Only</source>
        <translation>仅白南瓜</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2532"/>
        <source>Block Type</source>
        <translation>格子类型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2534"/>
        <location filename="../src/pages.cpp" line="2538"/>
        <location filename="../src/pages.cpp" line="2550"/>
        <location filename="../src/pages.cpp" line="2558"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2536"/>
        <source>Row Type (Spawn)</source>
        <translation>行判定（出怪）</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2540"/>
        <source>Game Scene</source>
        <translation>游戏场景</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2552"/>
        <source>Start Lawn Mowers</source>
        <translation>启动推车</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2553"/>
        <source>Clear Lawn Mowers</source>
        <translation>清除推车</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2554"/>
        <source>Reset Lawn Mowers</source>
        <translation>恢复推车</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2556"/>
        <source>Background Music</source>
        <translation>背景音乐</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2561"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
</context>
<context>
    <name>Pt::SlotsPage</name>
    <message>
        <location filename="../src/pages.cpp" line="2120"/>
        <source>Count of Slots</source>
        <translation>卡槽格数</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2121"/>
        <location filename="../src/pages.cpp" line="2137"/>
        <location filename="../src/pages.cpp" line="2159"/>
        <location filename="../src/pages.cpp" line="2162"/>
        <location filename="../src/pages.cpp" line="2165"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2123"/>
        <source>Hide Slots</source>
        <translation>隐藏卡槽</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2124"/>
        <source>Show Shovel</source>
        <translation>显示铲子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2125"/>
        <source>Lock Shovel</source>
        <translation>锁定铲子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2138"/>
        <source>Imitater</source>
        <translation>模仿者</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2139"/>
        <source>Hide</source>
        <translation>隐藏</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2141"/>
        <source>Ignore Sun</source>
        <translation>无视阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2142"/>
        <source>Seed No Cool Down</source>
        <translation>卡片无冷却</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2143"/>
        <source>Purple Seed Unlimited</source>
        <translation>紫卡无限制</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2144"/>
        <source>Planting Freely</source>
        <translation>自由种植</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2145"/>
        <source>Belt No Delay</source>
        <translation>传送无延迟</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2146"/>
        <source>Hide Menu Button</source>
        <translation>隐藏菜单键</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2148"/>
        <source>Seed</source>
        <translation>卡片</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2158"/>
        <source>Speed</source>
        <translation>攻速</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2161"/>
        <source>Cost</source>
        <translation>价格</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="2164"/>
        <source>Recharge</source>
        <translation>冷却</translation>
    </message>
</context>
<context>
    <name>Pt::SpawnBriefPage</name>
    <message>
        <location filename="../src/pages.cpp" line="1374"/>
        <source>Natural (Built-in Generate)</source>
        <translation>自然 (内置生成)</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1375"/>
        <source>Extreme (Filling Evenly)</source>
        <translation>极限 (均匀填充)</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1377"/>
        <source>Switch Detailed Mode</source>
        <translation>切换详细模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1378"/>
        <source>Spawning Counting</source>
        <translation>出怪数量统计</translation>
    </message>
</context>
<context>
    <name>Pt::SpawnCountPage</name>
    <message>
        <location filename="../src/pages.cpp" line="4719"/>
        <source>Spawning Counting</source>
        <translation>出怪数量统计</translation>
    </message>
</context>
<context>
    <name>Pt::SpawnDetailedPage</name>
    <message>
        <location filename="../src/pages.cpp" line="1726"/>
        <source>Set Seed</source>
        <translation>修改种子</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1737"/>
        <source>Add &gt;&gt;</source>
        <translation>添加 &gt;&gt;</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1738"/>
        <source>&lt;&lt; Delete</source>
        <translation>&lt;&lt; 删除</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1739"/>
        <source>Clear List</source>
        <translation>清空列表</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1741"/>
        <source>Natural Spawn</source>
        <translation>自然出怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1742"/>
        <source>Extreme Spawn</source>
        <translation>极限出怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1743"/>
        <source>Simulate Natural Spawn</source>
        <translation>模拟自然出怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1745"/>
        <source>Calls built-in function of game to generates zombies list.</source>
        <translation>调用游戏内置函数生成出怪列表。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1746"/>
        <source>Continuously and evenly populate the zombies list.</source>
        <translation>连续均匀地填充满出怪列表。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1747"/>
        <source>Randomly fill the zombies list according to some ratio.</source>
        <translation>按照一定比例随机填充出怪列表。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1749"/>
        <source>Limit Flag</source>
        <translation>限制旗帜</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1750"/>
        <source>Limit Yeti</source>
        <translation>限制雪人</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1751"/>
        <source>Limit Bungee</source>
        <translation>限制蹦极</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1752"/>
        <source>Limit Giga</source>
        <translation>限制红眼</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1754"/>
        <source>Weight of GigaGargantuar in non huge waves:</source>
        <translation>非大波红眼权重：</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1756"/>
        <source>Flag Zombie will only appear in each flag wave (huge wave).</source>
        <translation>旗帜只在每个旗帜波（大波）出现一只。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1757"/>
        <source>There will be only one Zombie Yeti.</source>
        <translation>雪人只出现一只。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1758"/>
        <source>Bungee Zombie will only appear in flag wave (huge wave).</source>
        <translation>蹦极只在旗帜波（大波）出现。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1759"/>
        <source>GigaGargantuar will only appear in selected wave(s) (20 waves total).</source>
        <translation>红眼只在所选的波次出现（总共 20 波）。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1761"/>
        <source>These check boxes shows or controls the waves of GigaGargantuar appear.</source>
        <translation>这些选项框显示或者控制红眼的出现波数。</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1763"/>
        <source>Reset</source>
        <translation>还原</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1764"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1766"/>
        <source>Switch Brief Mode</source>
        <translation>切换简略模式</translation>
    </message>
</context>
<context>
    <name>Pt::StatusPage</name>
    <message>
        <location filename="../src/pages.cpp" line="4597"/>
        <source>Auto Refresh</source>
        <translation>自动刷新</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4599"/>
        <source>Game Mode</source>
        <translation>游戏模式</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4600"/>
        <source>Game UI</source>
        <translation>游戏界面</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4601"/>
        <source>Running Time</source>
        <translation>进行时间</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4602"/>
        <source>Level Completed</source>
        <translation>完成轮数</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4603"/>
        <source>Total Waves</source>
        <translation>本轮总波数</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4604"/>
        <source>Past Waves</source>
        <translation>已刷新波数</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4605"/>
        <source>Total HP</source>
        <translation>本波总血量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4606"/>
        <source>Trigger HP</source>
        <translation>刷新触发血量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4607"/>
        <source>Count Down</source>
        <translation>刷新倒计时</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4608"/>
        <source>Huge Wave Count Down</source>
        <translation>大波刷新倒计时</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4609"/>
        <source>Plant Count</source>
        <translation>植物数量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4610"/>
        <source>Zombie Count</source>
        <translation>僵尸数量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4621"/>
        <source>Adventure</source>
        <translation>冒险模式</translation>
    </message>
</context>
<context>
    <name>Pt::TargetMapPage</name>
    <message>
        <location filename="../src/pages.cpp" line="4881"/>
        <location filename="../src/pages.cpp" line="4887"/>
        <source>Empty</source>
        <translation>空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4898"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4899"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4900"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="4905"/>
        <source>Target Map Modify</source>
        <translation>目标地图修改</translation>
    </message>
</context>
<context>
    <name>Pt::VasePage</name>
    <message>
        <location filename="../src/pages.cpp" line="3730"/>
        <location filename="../src/pages.cpp" line="3860"/>
        <location filename="../src/pages.cpp" line="3903"/>
        <source>Vase Count</source>
        <translation>花瓶数量</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3861"/>
        <source>Clear</source>
        <translation>清空</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3862"/>
        <source>Load</source>
        <translation>加载</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3863"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3865"/>
        <source>Row</source>
        <translation>行</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3866"/>
        <source>Column</source>
        <translation>列</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3867"/>
        <source>Skin</source>
        <translation>皮肤</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3868"/>
        <source>Type</source>
        <translation>类型</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3869"/>
        <source>Plant</source>
        <translation>植物</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3870"/>
        <source>Zombie</source>
        <translation>僵尸</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3871"/>
        <source>Sun</source>
        <translation>阳光</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="3924"/>
        <location filename="../src/pages.cpp" line="3958"/>
        <source>Empty</source>
        <translation>空</translation>
    </message>
</context>
<context>
    <name>Pt::ZombiesPage</name>
    <message>
        <location filename="../src/pages.cpp" line="1174"/>
        <source>Immediately Explode</source>
        <translation>立即爆炸</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1175"/>
        <source>Never Explode</source>
        <translation>从不爆炸</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1177"/>
        <source>Zombie Invisible</source>
        <translation>僵尸隐形</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1178"/>
        <source>Zombie Show</source>
        <translation>僵尸现形</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1180"/>
        <source>Zombie Invincible</source>
        <translation>僵尸无敌</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1181"/>
        <source>Zombie Weak</source>
        <translation>僵尸虚弱</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1183"/>
        <source>Stop Spawning</source>
        <translation>暂停出怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1184"/>
        <source>Zombies No Move</source>
        <translation>僵尸不动</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1186"/>
        <source>No Ice Slow Down</source>
        <translation>屏蔽寒冰减速</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1187"/>
        <source>No Butter Immobilize</source>
        <translation>屏蔽黄油固定</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1188"/>
        <source>No 3 Zombies Group</source>
        <translation>屏蔽三人组</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1189"/>
        <source>No Ice Trail</source>
        <translation>不留冰道</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1191"/>
        <source>No Throw Imp</source>
        <translation>不扔小鬼</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1192"/>
        <source>Gargantuar Eatable</source>
        <translation>巨人可被吃</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1193"/>
        <source>Zomboss No Move</source>
        <translation>僵王不动</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1194"/>
        <source>Balloon Burst</source>
        <translation>气球自爆</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1196"/>
        <source>Gather Zombies</source>
        <translation>吸怪</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1198"/>
        <source>Next Wave</source>
        <translation>下一波</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1200"/>
        <source>All Zombies</source>
        <translation>所有僵尸</translation>
    </message>
    <message>
        <location filename="../src/pages.cpp" line="1202"/>
        <source>Set</source>
        <translation>修改</translation>
    </message>
</context>
</TS>
