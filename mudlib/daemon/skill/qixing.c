 // TIE@FY3
inherit SKILL;
void setup(){
        set("name", "七星法");
        set("usage/spells", 1);
        set("effective_level",100);
        set("skill_class", "wudang");
}        
int practice_skill(object me)
{
        return notify_fail("七星法只能用学的\n");
}  
