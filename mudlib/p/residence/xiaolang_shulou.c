#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
  set("short",HIG"书楼"NOR);
  set("long",@LONG
由于生性随意洒脱，放荡不羁，萧十一郎并不是一个善于写字的人，但是
他爱字的程度超过了爱剑，对于各种字体，主人偏爱行书，这与他性格相符，
此间收藏了王羲之的许多真迹，当然夸张的草书也为主人所爱。
LONG
  );
  set("exits",([
                 "eastdown" : __DIR__"xiaolang2", 
                 "southeast": __DIR__"xiaolang_qilou",
                 "northeast": __DIR__"xiaolang_hualou",                
               ]));
    set("indoors", "residence");
        set("coor/x",14);
        set("coor/y",2035);
        set("coor/z",40);
        set("no_death_penalty",1);
        setup();
    replace_program(ROOM); 
}       
