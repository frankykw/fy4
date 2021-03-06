 // nine-moon-force.c
inherit SKILL;
#include <ansi.h> 
void setup(){
        set("name", "九阴心经");
        set("usage/force", 1);
        set("skill_class", "shenshui");
        set("learn_bonus", 10);
        set("practice_bonus", 5);
        set("black_white_ness", -10);
}
 
mixed hit_ob(object me,object victim, int damage_bonus)
{
        int extra;
        object weapon;
        string msg;
                
        if(!extra=me->query_temp("nine-moon-force_poison")) return ;
        
        if (weapon=me->query_temp("weapon")){
                if (weapon->query("skill_type")=="sword" && 
                        (me->query_skill_mapped("sword") == "nine-moon-sword"
                        || me->query_skill_mapped("sword") == "qingpingsword"))
                        {       
                        victim->add("kee",-extra/2);
                        victim->add("eff_kee",-extra/2);
                        victim->receive_wound("kee",1,me);
                        return MAG"$n只觉丝丝寒意透骨，似乎有一缕紫云般的雾气从$N兵刃上传来。\n"NOR;
                        }
        } else if (me->query_skill_mapped("unarmed") == "nine-moon-claw")
                {
                        victim->add("kee",-extra);
                        victim->add("eff_kee",-extra/2);
                        victim->receive_wound("kee",1,me);
                        msg=MAG"一缕紫云般的雾气一闪，$n只觉冷厉的阴风如刺如锥般从$N指尖传来。\n"NOR;
                        return msg;
                }
}   
/*int valid_learn(object me) 
{ 
    if( (string)me->query("gender") != "女性" ){
        return notify_fail("九阴心经是只有女子才能练的内功。\n");
    }
    return 1; 
} 
mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
    mixed foo;
    
    foo = ::hit_ob(me, victim, damage_bonus, factor);
    if( intp(foo) && (damage_bonus + foo > 0) )
    {
if(random(3*(me->query_skill("nine-moon-force", 1)/2)) > 
            (damage_bonus + foo) )
        {
            victim->receive_wound("kee", (damage_bonus + foo));
            victim->apply_condition("ninemoonpoison", factor/2);
            return "$N的招式挟著一股阴寒无比的劲风使得$n不禁打了个寒噤。\n";
        }
    }
    return foo;
} 
*/      
