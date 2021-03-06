#include <ansi.h>
inherit NPC;
void create()
{
        set_name("催命符", ({ "cuiming fu", "fu" }) );
        set("long",
         "他的脸色是死灰色的，似已和这凄迷的冷雾融为一体。鼻子已融入雾里，\n嘴也融人雾里，只剩下那双鬼火般的眼睛。眼睛里没有光，也分不出黑白，\n但却充满了恶毒之意。\n");
        set("nickname", WHT "一见送终"NOR);
        set("combat_exp", 1200000);
        set("force",500);
        set("max_force",500);
        set_temp("apply/damage",60);
        set("no_arrest",1);
        set_skill("unarmed", 150);
        set_skill("force",100);
        set_skill("parry",80);
        set_skill("dodge", 100);
        set_skill("move",100);
        set_skill("whip",150);
        set_skill("thunderwhip",120);
        set_skill("hawk-steps",150);
        set_skill("skyforce",100);
        set_skill("literate",100);
        set_skill("yunwu-strike",150);
        
        map_skill("unarmed","yunwu-strike");
        map_skill("whip","thunderwhip");
        map_skill("dodge","hawk-steps");
        map_skill("move","hawk-steps");
        map_skill("force","skyforce");
        
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "whip.tianleiyiji" :),
        }) );
        
        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/ywhip")->wield();
} 
void init()
{
        ::init();
        add_action("do_get","get");
} 
int do_get(string arg)
{
        string what,where;
        object me;
        me=this_player();
        if(!arg) return notify_fail("你想拿什么？\n");
        if(sscanf(arg,"%s from %s",what, where) !=2) return 0;
        if((where == "fentou" || where == "坟头" ))
        {
                message_vision("催命符伸手拦住$N.\n",me);
                command("say 想拿解药，先过了我这一关再说。");
                return 1;
        }
}   
