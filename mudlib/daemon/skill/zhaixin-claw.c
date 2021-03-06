 // nine-moon-claw.c
#include <ansi.h> 
inherit SKILL;
void setup(){
        set("name", "摘心手");
        set("usage/unarmed", 1);
        set("effective_level", 190);
        set("skill_class", "huashan");
        set("learn_bonus", -400);
        set("practice_bonus", 5);
        set("practice_limit",100);
        set("black_white_ness", -10);
        set("unarmed_parry_msg", ({
        "$n指尖发出丝丝寒气抓向$N手腕，$N急忙沉腕避开。\n",
                "$n左手一沉，右手旁引，$N只觉手中一空，招式击偏。 \n",
        }) );
        action = ({
        ([      "action":               
"$N左手直抓，右手斜挥，一招“摘星揽月”抓向$n$l",
                "dodge":                100,
                "parry":                140,
                "force":                100,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N一招“北岭折梅”，左手横胸，右手成爪，直击$n$l",
                "dodge":                150,
                "parry":                100,
                "force":                170,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N使出“长空紫气”，身形闪动间，爪影森森攻向$n$l",
                "dodge":                50,
                "parry":                120,
                "force":                140,
                "damage_type":  "抓伤"
        ]),
        ([      "action":               
"$N回步斜身，右手成爪反挥一个圆弧，一式“鹞子翻身”击向$n$l",
                "dodge":                310,
                "parry":                200,
                "force":                290,
                "damage_type":  "抓伤"
        ]),
        });
}
int valid_learn(object me)
{
    if( me->query("bellicosity")>50)
        return notify_fail("你现在心有嗔念，无法静心下来领会师傅的教导。\n");  
    return ::valid_learn(me);
} 
int practice_skill(object me)
{
    if( (int)me->query("force") < 5 ){
        return notify_fail("你的内力不够了，休息一下再练吧。\n");
    }
    if( (int)me->query("max_force") < 100 ){
        return notify_fail("你的内力太弱，无法练摘心爪。\n");
        }    
    if(!::practice_skill(me)){
        return 0;
    }
    me->add("force", -5);
    return 1;
}    
