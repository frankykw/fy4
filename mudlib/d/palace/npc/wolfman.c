 inherit NPC;
#include <ansi.h> 
void create()
{
        set_name(WHT"人形怪物"NOR, ({ "wolf man"}) );
        set("gender", "男性" );
        set("age", 30+random(20));
        set("long",
                "一个满身灰白色的长毛，望之有如人形的怪物，这怪物居然也有手足，腰间
围着一块豹皮，左手持火，右手却提着一只血淋淋的的山狼！\n");
        set("attitude", "aggressive");
        set("bellicosity",300000);
        
        set("reward_npc", 1);
        set("difficulty",10);
        
        set("combat_exp", 4500000);
        set("force",2000);
        set("max_force",2000);
        set("force_factor",60);
        
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("force",200);
        set_skill("lingxi-zhi",160);
        set_skill("hammer",200);
        set_skill("assasin-hammer",180);
        set_skill("parry",200);
        
        map_skill("unarmed","lingxi-zhi");
        map_skill("dodge","hawk-steps");
        map_skill("hammer", "assasin-hammer");
        map_skill("parry","assasin-hammer");
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        set("no_busy",10); 
        setup();
        
   carry_object(__DIR__"obj/wolf_hammer")->wield();
        carry_object(__DIR__"obj/raw_cloth")->wear();
        if (!random(5)) carry_object(__DIR__"obj/hammerbook");
}       
