//
// Created by lsc on 21-01-29.
//


#pragma once



#include <tea++/utils/string_t.h>

namespace teacc::color
{


enum name
{
    
    /*0   */ Black            [[maybe_unused]]   =0,//#000000	rgb(128,0,0)	hsl(0,100%,25%)
    /*1   */ Maroon           [[maybe_unused]]   ,//#800000	rgb(128,0,0)	hsl(0,100%,25%)
    /*2   */ Green            [[maybe_unused]]   ,//#008000	rgb(0,128,0)	hsl(120,100%,25%)
    /*3   */ Olive            [[maybe_unused]]   ,//#808000	rgb(128,128,0)	hsl(60,100%,25%)
    /*4   */ Navy             [[maybe_unused]]   ,//#000080	rgb(0,0,128)	hsl(240,100%,25%)
    /*5   */ Purple           [[maybe_unused]]   ,//#800080	rgb(128,0,128)	hsl(300,100%,25%)
    /*6   */ Teal             [[maybe_unused]]   ,//#008080	rgb(0,128,128)	hsl(180,100%,25%)
    /*7   */ Silver           [[maybe_unused]]   ,//#c0c0c0	rgb(192,192,192)	hsl(0,0%,75%)
    /*8   */ Grey             [[maybe_unused]]   ,//#808080	rgb(128,128,128)	hsl(0,0%,50%)
    /*9   */ Red              [[maybe_unused]]   ,//#ff0000	rgb(255,0,0)	hsl(0,100%,50%)
    /*10  */ Lime             [[maybe_unused]]   ,//#00ff00	rgb(0,255,0)	hsl(120,100%,50%)
    /*11  */ Yellow           [[maybe_unused]]   ,//#ffff00	rgb(255,255,0)	hsl(60,100%,50%)
    /*12  */ Blue             [[maybe_unused]]   ,//#0000ff	rgb(0,0,255)	hsl(240,100%,50%)
    /*13  */ Fuchsia          [[maybe_unused]]   ,//#ff00ff	rgb(255,0,255)	hsl(300,100%,50%)
    /*14  */ Aqua             [[maybe_unused]]   ,//#00ffff	rgb(0,255,255)	hsl(180,100%,50%)
    /*15  */ White            [[maybe_unused]]   ,//#ffffff	rgb(255,255,255)	hsl(0,0%,100%)
    /*16  */ Grey0            [[maybe_unused]]   ,//#000000	rgb(0,0,0)	hsl(0,0%,0%)
    /*17  */ NavyBlue         [[maybe_unused]]   ,//#00005f	rgb(0,0,95)	hsl(240,100%,18%)
    /*18  */ DarkBlue         [[maybe_unused]]   ,//#000087	rgb(0,0,135)	hsl(240,100%,26%)
    /*19  */ Blue3            [[maybe_unused]]   ,//#0000af	rgb(0,0,175)	hsl(240,100%,34%)
    /*20  */ Blue4            [[maybe_unused]]   ,//#0000d7	rgb(0,0,215)	hsl(240,100%,42%)
    /*21  */ Blue1            [[maybe_unused]]   ,//#0000ff	rgb(0,0,255)	hsl(240,100%,50%)
    /*22  */ DarkGreen        [[maybe_unused]]   ,//#005f00	rgb(0,95,0)	hsl(120,100%,18%)
    /*23  */ DeepSkyBlue4     [[maybe_unused]]   ,//#005f5f	rgb(0,95,95)	hsl(180,100%,18%)
    /*24  */ DeepSkyBlue5     [[maybe_unused]]   ,//#005f87	rgb(0,95,135)	hsl(97,100%,26%)
    /*25  */ DeepSkyBlue6     [[maybe_unused]]   ,//#005faf	rgb(0,95,175)	hsl(07,100%,34%)
    /*26  */ DodgerBlue3      [[maybe_unused]]   ,//#005fd7	rgb(0,95,215)	hsl(13,100%,42%)
    /*27  */ DodgerBlue2      [[maybe_unused]]   ,//#005fff	rgb(0,95,255)	hsl(17,100%,50%)
    /*28  */ Green4           [[maybe_unused]]   ,//#008700	rgb(0,135,0)	hsl(120,100%,26%)
    /*29  */ SpringGreen4     [[maybe_unused]]   ,//#00875f	rgb(0,135,95)	hsl(62,100%,26%)
    /*30  */ Turquoise4       [[maybe_unused]]   ,//#008787	rgb(0,135,135)	hsl(180,100%,26%)
    /*31  */ DeepSkyBlue3     [[maybe_unused]]   ,//#0087af	rgb(0,135,175)	hsl(93,100%,34%)
    /*32  */ DeepSkyBlue7     [[maybe_unused]]   ,//#0087d7	rgb(0,135,215)	hsl(02,100%,42%)
    /*33  */ DodgerBlue1      [[maybe_unused]]   ,//#0087ff	rgb(0,135,255)	hsl(08,100%,50%)
    /*34  */ Green3           [[maybe_unused]]   ,//#00af00	rgb(0,175,0)	hsl(120,100%,34%)
    /*35  */ SpringGreen3     [[maybe_unused]]   ,//#00af5f	rgb(0,175,95)	hsl(52,100%,34%)
    /*36  */ DarkCyan         [[maybe_unused]]   ,//#00af87	rgb(0,175,135)	hsl(66,100%,34%)
    /*37  */ LightSeaGreen    [[maybe_unused]]   ,//#00afaf	rgb(0,175,175)	hsl(180,100%,34%)
    /*38  */ DeepSkyBlue2     [[maybe_unused]]   ,//#00afd7	rgb(0,175,215)	hsl(91,100%,42%)
    /*39  */ DeepSkyBlue1     [[maybe_unused]]   ,//#00afff	rgb(0,175,255)	hsl(98,100%,50%)
    /*40  */ Green5           [[maybe_unused]]   ,//#00d700	rgb(0,215,0)	hsl(120,100%,42%)
    /*41  */ SpringGreen5     [[maybe_unused]]   ,//#00d75f	rgb(0,215,95)	hsl(46,100%,42%)
    /*42  */ SpringGreen2     [[maybe_unused]]   ,//#00d787	rgb(0,215,135)	hsl(57,100%,42%)
    /*43  */ Cyan3            [[maybe_unused]]   ,//#00d7af	rgb(0,215,175)	hsl(68,100%,42%)
    /*44  */ DarkTurquoise    [[maybe_unused]]   ,//#00d7d7	rgb(0,215,215)	hsl(180,100%,42%)
    /*45  */ Turquoise2       [[maybe_unused]]   ,//#00d7ff	rgb(0,215,255)	hsl(89,100%,50%)
    /*46  */ Green1           [[maybe_unused]]   ,//#00ff00	rgb(0,255,0)	hsl(120,100%,50%)
    /*47  */ SpringGreen6     [[maybe_unused]]   ,//#00ff5f	rgb(0,255,95)	hsl(42,100%,50%)
    /*48  */ SpringGreen1     [[maybe_unused]]   ,//#00ff87	rgb(0,255,135)	hsl(51,100%,50%)
    /*49  */ MediumSpringGreen[[maybe_unused]]   ,//#00ffaf	rgb(0,255,175)	hsl(61,100%,50%)
    /*50  */ Cyan2            [[maybe_unused]]   ,//#00ffd7	rgb(0,255,215)	hsl(70,100%,50%)
    /*51  */ Cyan1            [[maybe_unused]]   ,//#00ffff	rgb(0,255,255)	hsl(180,100%,50%)
    /*52  */ DarkRed          [[maybe_unused]]   ,//#5f0000	rgb(95,0,0)	hsl(0,100%,18%)
    /*53  */ DeepPink4        [[maybe_unused]]   ,//#5f005f	rgb(95,0,95)	hsl(300,100%,18%)
    /*54  */ Purple4          [[maybe_unused]]   ,//#5f0087	rgb(95,0,135)	hsl(82,100%,26%)
    /*55  */ Purple5          [[maybe_unused]]   ,//#5f00af	rgb(95,0,175)	hsl(72,100%,34%)
    /*56  */ Purple3          [[maybe_unused]]   ,//#5f00d7	rgb(95,0,215)	hsl(66,100%,42%)
    /*57  */ BlueViolet       [[maybe_unused]]   ,//#5f00ff	rgb(95,0,255)	hsl(62,100%,50%)
    /*58  */ Orange4          [[maybe_unused]]   ,//#5f5f00	rgb(95,95,0)	hsl(60,100%,18%)
    /*59  */ Grey37           [[maybe_unused]]   ,//#5f5f5f	rgb(95,95,95)	hsl(0,0%,37%)
    /*60  */ MediumPurple4    [[maybe_unused]]   ,//#5f5f87	rgb(95,95,135)	hsl(240,17%,45%)
    /*61  */ SlateBlue3       [[maybe_unused]]   ,//#5f5faf	rgb(95,95,175)	hsl(240,33%,52%)
    /*62  */ SlateBlue4       [[maybe_unused]]   ,//#5f5fd7	rgb(95,95,215)	hsl(240,60%,60%)
    /*63  */ RoyalBlue1       [[maybe_unused]]   ,//#5f5fff	rgb(95,95,255)	hsl(240,100%,68%)
    /*64  */ Chartreuse4      [[maybe_unused]]   ,//#5f8700	rgb(95,135,0)	hsl(7,100%,26%)
    /*65  */ DarkSeaGreen4    [[maybe_unused]]   ,//#5f875f	rgb(95,135,95)	hsl(120,17%,45%)
    /*66  */ PaleTurquoise4   [[maybe_unused]]   ,//#5f8787	rgb(95,135,135)	hsl(180,17%,45%)
    /*67  */ SteelBlue        [[maybe_unused]]   ,//#5f87af	rgb(95,135,175)	hsl(210,33%,52%)
    /*68  */ SteelBlue3       [[maybe_unused]]   ,//#5f87d7	rgb(95,135,215)	hsl(220,60%,60%)
    /*69  */ CornflowerBlue   [[maybe_unused]]   ,//#5f87ff	rgb(95,135,255)	hsl(225,100%,68%)
    /*70  */ Chartreuse3      [[maybe_unused]]   ,//#5faf00	rgb(95,175,0)	hsl(7,100%,34%)
    /*71  */ DarkSeaGreen5    [[maybe_unused]]   ,//#5faf5f	rgb(95,175,95)	hsl(120,33%,52%)
    /*72  */ CadetBlue        [[maybe_unused]]   ,//#5faf87	rgb(95,175,135)	hsl(150,33%,52%)
    /*73  */ CadetBlue2       [[maybe_unused]]   ,//#5fafaf	rgb(95,175,175)	hsl(180,33%,52%)
    /*74  */ SkyBlue3         [[maybe_unused]]   ,//#5fafd7	rgb(95,175,215)	hsl(200,60%,60%)
    /*75  */ SteelBlue1       [[maybe_unused]]   ,//#5fafff	rgb(95,175,255)	hsl(210,100%,68%)
    /*76  */ Chartreuse5      [[maybe_unused]]   ,//#5fd700	rgb(95,215,0)	hsl(3,100%,42%)
    /*77  */ PaleGreen3       [[maybe_unused]]   ,//#5fd75f	rgb(95,215,95)	hsl(120,60%,60%)
    /*78  */ SeaGreen3        [[maybe_unused]]   ,//#5fd787	rgb(95,215,135)	hsl(140,60%,60%)
    /*79  */ Aquamarine3      [[maybe_unused]]   ,//#5fd7af	rgb(95,215,175)	hsl(160,60%,60%)
    /*80  */ MediumTurquoise  [[maybe_unused]]   ,//#5fd7d7	rgb(95,215,215)	hsl(180,60%,60%)
    /*81  */ SteelBlue4       [[maybe_unused]]   ,//#5fd7ff	rgb(95,215,255)	hsl(195,100%,68%)
    /*82  */ Chartreuse2      [[maybe_unused]]   ,//#5fff00	rgb(95,255,0)	hsl(7,100%,50%)
    /*83  */ SeaGreen2        [[maybe_unused]]   ,//#5fff5f	rgb(95,255,95)	hsl(120,100%,68%)
    /*84  */ SeaGreen1        [[maybe_unused]]   ,//#5fff87	rgb(95,255,135)	hsl(135,100%,68%)
    /*85  */ SeaGreen4        [[maybe_unused]]   ,//#5fffaf	rgb(95,255,175)	hsl(150,100%,68%)
    /*86  */ Aquamarine1      [[maybe_unused]]   ,//#5fffd7	rgb(95,255,215)	hsl(165,100%,68%)
    /*87  */ DarkSlateGray2   [[maybe_unused]]   ,//#5fffff	rgb(95,255,255)	hsl(180,100%,68%)
    /*88  */ DarkRed2         [[maybe_unused]]   ,//#870000	rgb(135,0,0)	hsl(0,100%,26%)
    /*89  */ DeepPink5        [[maybe_unused]]   ,//#87005f	rgb(135,0,95)	hsl(17,100%,26%)
    /*90  */ DarkMagenta      [[maybe_unused]]   ,//#870087	rgb(135,0,135)	hsl(300,100%,26%)
    /*91  */ DarkMagenta2     [[maybe_unused]]   ,//#8700af	rgb(135,0,175)	hsl(86,100%,34%)
    /*92  */ DarkViolet       [[maybe_unused]]   ,//#8700d7	rgb(135,0,215)	hsl(77,100%,42%)
    /*93  */ Purple2          [[maybe_unused]]   ,//#8700ff	rgb(135,0,255)	hsl(71,100%,50%)
    /*94  */ Orange5          [[maybe_unused]]   ,//#875f00	rgb(135,95,0)	hsl(2,100%,26%)
    /*95  */ LightPink4       [[maybe_unused]]   ,//#875f5f	rgb(135,95,95)	hsl(0,17%,45%)
    /*96  */ Plum4            [[maybe_unused]]   ,//#875f87	rgb(135,95,135)	hsl(300,17%,45%)
    /*97  */ MediumPurple3    [[maybe_unused]]   ,//#875faf	rgb(135,95,175)	hsl(270,33%,52%)
    /*98  */ MediumPurple5    [[maybe_unused]]   ,//#875fd7	rgb(135,95,215)	hsl(260,60%,60%)
    /*99  */ SlateBlue1       [[maybe_unused]]   ,//#875fff	rgb(135,95,255)	hsl(255,100%,68%)
    /*100 */ Yellow4          [[maybe_unused]]   ,//#878700	rgb(135,135,0)	hsl(60,100%,26%)
    /*101 */ Wheat4           [[maybe_unused]]   ,//#87875f	rgb(135,135,95)	hsl(60,17%,45%)
    /*102 */ Grey53           [[maybe_unused]]   ,//#878787	rgb(135,135,135)	hsl(0,0%,52%)
    /*103 */ LightSlateGrey   [[maybe_unused]]   ,//#8787af	rgb(135,135,175)	hsl(240,20%,60%)
    /*104 */ MediumPurple     [[maybe_unused]]   ,//#8787d7	rgb(135,135,215)	hsl(240,50%,68%)
    /*105 */ LightSlateBlue   [[maybe_unused]]   ,//#8787ff	rgb(135,135,255)	hsl(240,100%,76%)
    /*106 */ Yellow5          [[maybe_unused]]   ,//#87af00	rgb(135,175,0)	hsl(3,100%,34%)
    /*107 */ DarkOliveGreen3  [[maybe_unused]]   ,//#87af5f	rgb(135,175,95)	hsl(90,33%,52%)
    /*108 */ DarkSeaGreen     [[maybe_unused]]   ,//#87af87	rgb(135,175,135)	hsl(120,20%,60%)
    /*109 */ LightSkyBlue3    [[maybe_unused]]   ,//#87afaf	rgb(135,175,175)	hsl(180,20%,60%)
    /*110 */ LightSkyBlue4    [[maybe_unused]]   ,//#87afd7	rgb(135,175,215)	hsl(210,50%,68%)
    /*111 */ SkyBlue2         [[maybe_unused]]   ,//#87afff	rgb(135,175,255)	hsl(220,100%,76%)
    /*112 */ Chartreuse6      [[maybe_unused]]   ,//#87d700	rgb(135,215,0)	hsl(2,100%,42%)
    /*113 */ DarkOliveGreen4  [[maybe_unused]]   ,//#87d75f	rgb(135,215,95)	hsl(100,60%,60%)
    /*114 */ PaleGreen4       [[maybe_unused]]   ,//#87d787	rgb(135,215,135)	hsl(120,50%,68%)
    /*115 */ DarkSeaGreen3    [[maybe_unused]]   ,//#87d7af	rgb(135,215,175)	hsl(150,50%,68%)
    /*116 */ DarkSlateGray3   [[maybe_unused]]   ,//#87d7d7	rgb(135,215,215)	hsl(180,50%,68%)
    /*117 */ SkyBlue1         [[maybe_unused]]   ,//#87d7ff	rgb(135,215,255)	hsl(200,100%,76%)
    /*118 */ Chartreuse1      [[maybe_unused]]   ,//#87ff00	rgb(135,255,0)	hsl(8,100%,50%)
    /*119 */ LightGreen       [[maybe_unused]]   ,//#87ff5f	rgb(135,255,95)	hsl(105,100%,68%)
    /*120 */ LightGreen2      [[maybe_unused]]   ,//#87ff87	rgb(135,255,135)	hsl(120,100%,76%)
    /*121 */ PaleGreen1       [[maybe_unused]]   ,//#87ffaf	rgb(135,255,175)	hsl(140,100%,76%)
    /*122 */ Aquamarine2      [[maybe_unused]]   ,//#87ffd7	rgb(135,255,215)	hsl(160,100%,76%)
    /*123 */ DarkSlateGray1   [[maybe_unused]]   ,//#87ffff	rgb(135,255,255)	hsl(180,100%,76%)
    /*124 */ Red3             [[maybe_unused]]   ,//#af0000	rgb(175,0,0)	hsl(0,100%,34%)
    /*125 */ DeepPink6        [[maybe_unused]]   ,//#af005f	rgb(175,0,95)	hsl(27,100%,34%)
    /*126 */ MediumVioletRed  [[maybe_unused]]   ,//#af0087	rgb(175,0,135)	hsl(13,100%,34%)
    /*127 */ Magenta3         [[maybe_unused]]   ,//#af00af	rgb(175,0,175)	hsl(300,100%,34%)
    /*128 */ DarkViole2       [[maybe_unused]]   ,//#af00d7	rgb(175,0,215)	hsl(88,100%,42%)
    /*129 */ Purple6          [[maybe_unused]]   ,//#af00ff	rgb(175,0,255)	hsl(81,100%,50%)
    /*130 */ DarkOrange3      [[maybe_unused]]   ,//#af5f00	rgb(175,95,0)	hsl(2,100%,34%)
    /*131 */ IndianRed        [[maybe_unused]]   ,//#af5f5f	rgb(175,95,95)	hsl(0,33%,52%)
    /*132 */ HotPink3         [[maybe_unused]]   ,//#af5f87	rgb(175,95,135)	hsl(330,33%,52%)
    /*133 */ MediumOrchid3    [[maybe_unused]]   ,//#af5faf	rgb(175,95,175)	hsl(300,33%,52%)
    /*134 */ MediumOrchid     [[maybe_unused]]   ,//#af5fd7	rgb(175,95,215)	hsl(280,60%,60%)
    /*135 */ MediumPurple2    [[maybe_unused]]   ,//#af5fff	rgb(175,95,255)	hsl(270,100%,68%)
    /*136 */ DarkGoldenrod    [[maybe_unused]]   ,//#af8700	rgb(175,135,0)	hsl(6,100%,34%)
    /*137 */ LightSalmon3     [[maybe_unused]]   ,//#af875f	rgb(175,135,95)	hsl(30,33%,52%)
    /*138 */ RosyBrown        [[maybe_unused]]   ,//#af8787	rgb(175,135,135)	hsl(0,20%,60%)
    /*139 */ Grey63           [[maybe_unused]]   ,//#af87af	rgb(175,135,175)	hsl(300,20%,60%)
    /*140 */ MediumPurple6    [[maybe_unused]]   ,//#af87d7	rgb(175,135,215)	hsl(270,50%,68%)
    /*141 */ MediumPurple1    [[maybe_unused]]   ,//#af87ff	rgb(175,135,255)	hsl(260,100%,76%)
    /*142 */ Gold3            [[maybe_unused]]   ,//#afaf00	rgb(175,175,0)	hsl(60,100%,34%)
    /*143 */ DarkKhaki        [[maybe_unused]]   ,//#afaf5f	rgb(175,175,95)	hsl(60,33%,52%)
    /*144 */ NavajoWhite3     [[maybe_unused]]   ,//#afaf87	rgb(175,175,135)	hsl(60,20%,60%)
    /*145 */ Grey69           [[maybe_unused]]   ,//#afafaf	rgb(175,175,175)	hsl(0,0%,68%)
    /*146 */ LightSteelBlue3  [[maybe_unused]]   ,//#afafd7	rgb(175,175,215)	hsl(240,33%,76%)
    /*147 */ LightSteelBlue   [[maybe_unused]]   ,//#afafff	rgb(175,175,255)	hsl(240,100%,84%)
    /*148 */ Yellow3          [[maybe_unused]]   ,//#afd700	rgb(175,215,0)	hsl(1,100%,42%)
    /*149 */ DarkOliveGreen5  [[maybe_unused]]   ,//#afd75f	rgb(175,215,95)	hsl(80,60%,60%)
    /*150 */ DarkSeaGreen6    [[maybe_unused]]   ,//#afd787	rgb(175,215,135)	hsl(90,50%,68%)
    /*151 */ DarkSeaGreen2    [[maybe_unused]]   ,//#afd7af	rgb(175,215,175)	hsl(120,33%,76%)
    /*152 */ LightCyan3       [[maybe_unused]]   ,//#afd7d7	rgb(175,215,215)	hsl(180,33%,76%)
    /*153 */ LightSkyBlue1    [[maybe_unused]]   ,//#afd7ff	rgb(175,215,255)	hsl(210,100%,84%)
    /*154 */ GreenYellow      [[maybe_unused]]   ,//#afff00	rgb(175,255,0)	hsl(8,100%,50%)
    /*155 */ DarkOliveGreen2  [[maybe_unused]]   ,//#afff5f	rgb(175,255,95)	hsl(90,100%,68%)
    /*156 */ PaleGreen2       [[maybe_unused]]   ,//#afff87	rgb(175,255,135)	hsl(100,100%,76%)
    /*157 */ DarkSeaGreen7    [[maybe_unused]]   ,//#afffaf	rgb(175,255,175)	hsl(120,100%,84%)
    /*158 */ DarkSeaGreen1    [[maybe_unused]]   ,//#afffd7	rgb(175,255,215)	hsl(150,100%,84%)
    /*159 */ PaleTurquoise1   [[maybe_unused]]   ,//#afffff	rgb(175,255,255)	hsl(180,100%,84%)
    /*160 */ Red4             [[maybe_unused]]   ,//#d70000	rgb(215,0,0)	hsl(0,100%,42%)
    /*161 */ DeepPink3        [[maybe_unused]]   ,//#d7005f	rgb(215,0,95)	hsl(33,100%,42%)
    /*162 */ DeepPink7        [[maybe_unused]]   ,//#d70087	rgb(215,0,135)	hsl(22,100%,42%)
    /*163 */ Magenta4         [[maybe_unused]]   ,//#d700af	rgb(215,0,175)	hsl(11,100%,42%)
    /*164 */ Magenta5         [[maybe_unused]]   ,//#d700d7	rgb(215,0,215)	hsl(300,100%,42%)
    /*165 */ Magenta2         [[maybe_unused]]   ,//#d700ff	rgb(215,0,255)	hsl(90,100%,50%)
    /*166 */ DarkOrange4      [[maybe_unused]]   ,//#d75f00	rgb(215,95,0)	hsl(6,100%,42%)
    /*167 */ IndianRed2       [[maybe_unused]]   ,//#d75f5f	rgb(215,95,95)	hsl(0,60%,60%)
    /*168 */ HotPink4         [[maybe_unused]]   ,//#d75f87	rgb(215,95,135)	hsl(340,60%,60%)
    /*169 */ HotPink2         [[maybe_unused]]   ,//#d75faf	rgb(215,95,175)	hsl(320,60%,60%)
    /*170 */ Orchid           [[maybe_unused]]   ,//#d75fd7	rgb(215,95,215)	hsl(300,60%,60%)
    /*171 */ MediumOrchid1    [[maybe_unused]]   ,//#d75fff	rgb(215,95,255)	hsl(285,100%,68%)
    /*172 */ Orange3          [[maybe_unused]]   ,//#d78700	rgb(215,135,0)	hsl(7,100%,42%)
    /*173 */ LightSalmon4     [[maybe_unused]]   ,//#d7875f	rgb(215,135,95)	hsl(20,60%,60%)
    /*174 */ LightPink3       [[maybe_unused]]   ,//#d78787	rgb(215,135,135)	hsl(0,50%,68%)
    /*175 */ Pink3            [[maybe_unused]]   ,//#d787af	rgb(215,135,175)	hsl(330,50%,68%)
    /*176 */ Plum3            [[maybe_unused]]   ,//#d787d7	rgb(215,135,215)	hsl(300,50%,68%)
    /*177 */ Violet           [[maybe_unused]]   ,//#d787ff	rgb(215,135,255)	hsl(280,100%,76%)
    /*178 */ Gold4            [[maybe_unused]]   ,//#d7af00	rgb(215,175,0)	hsl(8,100%,42%)
    /*179 */ LightGoldenrod3  [[maybe_unused]]   ,//#d7af5f	rgb(215,175,95)	hsl(40,60%,60%)
    /*180 */ Tan              [[maybe_unused]]   ,//#d7af87	rgb(215,175,135)	hsl(30,50%,68%)
    /*181 */ MistyRose3       [[maybe_unused]]   ,//#d7afaf	rgb(215,175,175)	hsl(0,33%,76%)
    /*182 */ Thistle3         [[maybe_unused]]   ,//#d7afd7	rgb(215,175,215)	hsl(300,33%,76%)
    /*183 */ Plum2            [[maybe_unused]]   ,//#d7afff	rgb(215,175,255)	hsl(270,100%,84%)
    /*184 */ Yellow6          [[maybe_unused]]   ,//#d7d700	rgb(215,215,0)	hsl(60,100%,42%)
    /*185 */ Khaki3           [[maybe_unused]]   ,//#d7d75f	rgb(215,215,95)	hsl(60,60%,60%)
    /*186 */ LightGoldenrod2  [[maybe_unused]]   ,//#d7d787	rgb(215,215,135)	hsl(60,50%,68%)
    /*187 */ LightYellow3     [[maybe_unused]]   ,//#d7d7af	rgb(215,215,175)	hsl(60,33%,76%)
    /*188 */ Grey84           [[maybe_unused]]   ,//#d7d7d7	rgb(215,215,215)	hsl(0,0%,84%)
    /*189 */ LightSteelBlue1  [[maybe_unused]]   ,//#d7d7ff	rgb(215,215,255)	hsl(240,100%,92%)
    /*190 */ Yellow2          [[maybe_unused]]   ,//#d7ff00	rgb(215,255,0)	hsl(9,100%,50%)
    /*191 */ DarkOliveGreen1  [[maybe_unused]]   ,//#d7ff5f	rgb(215,255,95)	hsl(75,100%,68%)
    /*192 */ DarkOliveGreen6  [[maybe_unused]]   ,//#d7ff87	rgb(215,255,135)	hsl(80,100%,76%)
    /*193 */ DarkSeaGreen8    [[maybe_unused]]   ,//#d7ffaf	rgb(215,255,175)	hsl(90,100%,84%)
    /*194 */ Honeydew2        [[maybe_unused]]   ,//#d7ffd7	rgb(215,255,215)	hsl(120,100%,92%)
    /*195 */ LightCyan1       [[maybe_unused]]   ,//#d7ffff	rgb(215,255,255)	hsl(180,100%,92%)
    /*196 */ Red1             [[maybe_unused]]   ,//#ff0000	rgb(255,0,0)	hsl(0,100%,50%)
    /*197 */ DeepPink2        [[maybe_unused]]   ,//#ff005f	rgb(255,0,95)	hsl(37,100%,50%)
    /*198 */ DeepPink1        [[maybe_unused]]   ,//#ff0087	rgb(255,0,135)	hsl(28,100%,50%)
    /*199 */ DeepPink8        [[maybe_unused]]   ,//#ff00af	rgb(255,0,175)	hsl(18,100%,50%)
    /*200 */ Magenta6         [[maybe_unused]]   ,//#ff00d7	rgb(255,0,215)	hsl(09,100%,50%)
    /*201 */ Magenta1         [[maybe_unused]]   ,//#ff00ff	rgb(255,0,255)	hsl(300,100%,50%)
    /*202 */ OrangeRed1       [[maybe_unused]]   ,//#ff5f00	rgb(255,95,0)	hsl(2,100%,50%)
    /*203 */ IndianRed1       [[maybe_unused]]   ,//#ff5f5f	rgb(255,95,95)	hsl(0,100%,68%)
    /*204 */ IndianRed3       [[maybe_unused]]   ,//#ff5f87	rgb(255,95,135)	hsl(345,100%,68%)
    /*205 */ HotPink          [[maybe_unused]]   ,//#ff5faf	rgb(255,95,175)	hsl(330,100%,68%)
    /*206 */ HotPin2          [[maybe_unused]]   ,//#ff5fd7	rgb(255,95,215)	hsl(315,100%,68%)
    /*207 */ MediumOrchid2    [[maybe_unused]]   ,//#ff5fff	rgb(255,95,255)	hsl(300,100%,68%)
    /*208 */ DarkOrange       [[maybe_unused]]   ,//#ff8700	rgb(255,135,0)	hsl(1,100%,50%)
    /*209 */ Salmon1          [[maybe_unused]]   ,//#ff875f	rgb(255,135,95)	hsl(15,100%,68%)
    /*210 */ LightCoral       [[maybe_unused]]   ,//#ff8787	rgb(255,135,135)	hsl(0,100%,76%)
    /*211 */ PaleVioletRed1   [[maybe_unused]]   ,//#ff87af	rgb(255,135,175)	hsl(340,100%,76%)
    /*212 */ Orchid2          [[maybe_unused]]   ,//#ff87d7	rgb(255,135,215)	hsl(320,100%,76%)
    /*213 */ Orchid1          [[maybe_unused]]   ,//#ff87ff	rgb(255,135,255)	hsl(300,100%,76%)
    /*214 */ Orange1          [[maybe_unused]]   ,//#ffaf00	rgb(255,175,0)	hsl(1,100%,50%)
    /*215 */ SandyBrown       [[maybe_unused]]   ,//#ffaf5f	rgb(255,175,95)	hsl(30,100%,68%)
    /*216 */ LightSalmon1     [[maybe_unused]]   ,//#ffaf87	rgb(255,175,135)	hsl(20,100%,76%)
    /*217 */ LightPink1       [[maybe_unused]]   ,//#ffafaf	rgb(255,175,175)	hsl(0,100%,84%)
    /*218 */ Pink1            [[maybe_unused]]   ,//#ffafd7	rgb(255,175,215)	hsl(330,100%,84%)
    /*219 */ Plum1            [[maybe_unused]]   ,//#ffafff	rgb(255,175,255)	hsl(300,100%,84%)
    /*220 */ Gold1            [[maybe_unused]]   ,//#ffd700	rgb(255,215,0)	hsl(0,100%,50%)
    /*221 */ LightGoldenrod4  [[maybe_unused]]   ,//#ffd75f	rgb(255,215,95)	hsl(45,100%,68%)
    /*222 */ LightGoldenrod5  [[maybe_unused]]   ,//#ffd787	rgb(255,215,135)	hsl(40,100%,76%)
    /*223 */ NavajoWhite1     [[maybe_unused]]   ,//#ffd7af	rgb(255,215,175)	hsl(30,100%,84%)
    /*224 */ MistyRose1       [[maybe_unused]]   ,//#ffd7d7	rgb(255,215,215)	hsl(0,100%,92%)
    /*225 */ Thistle1         [[maybe_unused]]   ,//#ffd7ff	rgb(255,215,255)	hsl(300,100%,92%)
    /*226 */ Yellow1          [[maybe_unused]]   ,//#ffff00	rgb(255,255,0)	hsl(60,100%,50%)
    /*227 */ LightGoldenrod1  [[maybe_unused]]   ,//#ffff5f	rgb(255,255,95)	hsl(60,100%,68%)
    /*228 */ Khaki1           [[maybe_unused]]   ,//#ffff87	rgb(255,255,135)	hsl(60,100%,76%)
    /*229 */ Wheat1           [[maybe_unused]]   ,//#ffffaf	rgb(255,255,175)	hsl(60,100%,84%)
    /*230 */ Cornsilk1        [[maybe_unused]]   ,//#ffffd7	rgb(255,255,215)	hsl(60,100%,92%)
    /*231 */ Grey100          [[maybe_unused]]   ,//#ffffff	rgb(255,255,255)	hsl(0,0%,100%)
    /*232 */ Grey3            [[maybe_unused]]   ,//#080808	rgb(8,8,8)	hsl(0,0%,3%)
    /*233 */ Grey7            [[maybe_unused]]   ,//#121212	rgb(18,18,18)	hsl(0,0%,7%)
    /*234 */ Grey11           [[maybe_unused]]   ,//#1c1c1c	rgb(28,28,28)	hsl(0,0%,10%)
    /*235 */ Grey15           [[maybe_unused]]   ,//#262626	rgb(38,38,38)
    /*236 */ Grey19           [[maybe_unused]]   ,//#303030	rgb(48,48,48)	hsl(0,0%,18%)
    /*237 */ Grey23           [[maybe_unused]]   ,//#3a3a3a	rgb(58,58,58)	hsl(0,0%,22%)
    /*238 */ Grey27           [[maybe_unused]]   ,//#444444	rgb(68,68,68)	hsl(0,0%,26%)
    /*239 */ Grey30           [[maybe_unused]]   ,//#4e4e4e	rgb(78,78,78)	hsl(0,0%,30%)
    /*240 */ Grey35           [[maybe_unused]]   ,//#585858	rgb(88,88,88)	hsl(0,0%,34%)
    /*241 */ Grey39           [[maybe_unused]]   ,//#626262	rgb(98,98,98)	hsl(0,0%,37%)
    /*242 */ Grey42           [[maybe_unused]]   ,//#6c6c6c	rgb(108,108,108)	hsl(0,0%,40%)
    /*243 */ Grey46           [[maybe_unused]]   ,//#767676	rgb(118,118,118)	hsl(0,0%,46%)
    /*244 */ Grey50           [[maybe_unused]]   ,//#808080	rgb(128,128,128)	hsl(0,0%,50%)
    /*245 */ Grey54           [[maybe_unused]]   ,//#8a8a8a	rgb(138,138,138)	hsl(0,0%,54%)
    /*246 */ Grey58           [[maybe_unused]]   ,//#949494	rgb(148,148,148)	hsl(0,0%,58%)
    /*247 */ Grey62           [[maybe_unused]]   ,//#9e9e9e	rgb(158,158,158)	hsl(0,0%,61%)
    /*248 */ Grey66           [[maybe_unused]]   ,//#a8a8a8	rgb(168,168,168)	hsl(0,0%,65%)
    /*249 */ Grey70           [[maybe_unused]]   ,//#b2b2b2	rgb(178,178,178)	hsl(0,0%,69%)
    /*250 */ Grey74           [[maybe_unused]]   ,//#bcbcbc	rgb(188,188,188)	hsl(0,0%,73%)
    /*251 */ Grey78           [[maybe_unused]]   ,//#c6c6c6	rgb(198,198,198)	hsl(0,0%,77%)
    /*252 */ Grey82           [[maybe_unused]]   ,//#d0d0d0	rgb(208,208,208)	hsl(0,0%,81%)
    /*253 */ Grey85           [[maybe_unused]]   ,//#dadada	rgb(218,218,218)	hsl(0,0%,85%)
    /*254 */ Grey89           [[maybe_unused]]   ,//#e4e4e4	rgb(228,228,228)	hsl(0,0%,89%)
    /*255 */ Grey93           [[maybe_unused]]   ,//#eeeeee	rgb(238,238,238)	hsl(0,0%,93%)
    /*Reset*/ Reset           [[maybe_unused]]

};

std::string UTILS ansi(color::name c);

}


