#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("熊猫儿", ({ "xiong maoer","maoer" }) );
        set("gender", "男性" );
        set("title", HIR"江湖第一游侠儿"NOR );
        set("long",
        "只见此人身长八尺，沈眉大眼，腰畔斜插着柄无鞘短刀，手里提着\n只发亮的酒葫芦，一面高歌，一面痛欢。\n"
                );
        set("attitude", "peaceful");
        set("chat_chance_combat",50);
        set("chat_msg_combat",({
                      (:perform_action,"blade.jichulianhuan":),
                      (:perform_action,"dodge.shenjimiaosuan":),
        }));
        set("age", 25);
        set("cps", 40);
        set("int", 50);
        set("per", 40);
        set("cor", 40);
        set("agi", 30);
        set("combat_exp", 800000);
        set("force", 1000);
        set("max_force", 1000);
        set("mana", 1000);
        set("max_mana", 1000);
        set("force_factor", 30); 
        set_temp("apply/armor",50);
        set_temp("apply/attack", 50);
        
        set("chat_chance", 1);
        set("chat_msg", ({
        "熊猫儿放声高歌：千金挥手美人情，落魄自古多英雄，且把壶中陈香酒，萍水江湖一笑逢。\n",
        "熊猫儿苦着脸道：沈浪啊沈浪，你到底在哪里？？\n",
                }) );
        set("inquiry",  ([
                "沈浪" : "唉，沈浪啊沈浪，你是否还活在人间？\n",
                "朱七七" : "啊！你可知道那丫头的消息么？她。。还好么？\n",
                "王怜花" : "天底下怎么会生出这种魔星？？\n",
                "快活王" : "快活王和沈浪究竟谁会笑到最后呢？\n",
                ])); 
        set_skill("unarmed", 100);
        set_skill("blade", 100);
        set_skill("shenji-blade", 100);
        set_skill("dodge", 100);
        set_skill("parry", 100);
        set_skill("move", 100);
        set_skill("shenji-steps", 100);
        set_skill("dragonstrike",120);
        
        map_skill("unarmed","dragonstrike");
        map_skill("dodge", "shenji-steps");
        map_skill("blade", "shenji-blade");
        map_skill("parry", "shenji-blade");
                
        setup();
        carry_object("/d/loulan/obj/blade")->wield();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/d/loulan/obj/winepot");
}       
