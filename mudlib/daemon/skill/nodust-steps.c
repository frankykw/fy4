 // nodust-steps.c
inherit SKILL;
void setup(){
        set("name", "无尘步法");
        set("usage/dodge", 1);
        set("usage/move", 1);
        set("effective_level", 200);
        set("learn_bonus", 20);
        set("practice_bonus", -60);
        set("black_white_ness", 20);
        set("skill_class", "ghost");           
        set("dodge_msg", ({
        "$n一招「轻烟缥缈」轻轻巧巧地避了开去。\n",
        "只见$n身影一晃，一式「青云直上」早已避在七尺之外。\n",
        "$n使出「凌空飞渡」，轻轻松松地闪过。\n",
        }) );
} 
int valid_learn(object me)
{
    if( (int)me->query("max_force") < 150 ){
        return notify_fail("你的内力不够，没有办法练无尘步法。\n");
        }
    return 1;
} 
int practice_skill(object me)
{
    if((int)me->query("force") < 3 ){
        return notify_fail("你的气或内力不够，不能练无尘步法。\n");
    }
    if(!::practice_skill(me)) {
        return 0;
    }
    me->add("force", -3);
    return 1;
}      
