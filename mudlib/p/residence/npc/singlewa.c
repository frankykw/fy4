 // banker.c
#include <ansi.h>
inherit NPC;
inherit F_BANKPAWNOWNER;
inherit F_VENDOR;
string ask_me(object who); 
void create()
{
        set_name("香山居士", ({ "waiter", "mentong" }) );
        set("title", "棋友");
        set("gender", "男性" );
        set("age", 55);
        set("richness",1000000);
        set("str", 82);
        set("cor", 30);
        set("cps", 30);
        set("int", 26);
        set("per", 53);
        set("con", 24);
        set("spi", 30);
        set("kar", 25);
        set("long",
"一个手执棋子，对着棋盘发愣的书呆子。长期守在此处等云游的主人回来对弈。\n"
                );
        set("chat_chance", 2);
        set("chat_msg", ({
                "香山居士轻轻将棋子放在棋盘上，叹了口气，又拿了起来。\n",
                }) );
        set("combat_exp", 60000000);
        set("fly_target",1);
        set("attitude", "friendly");
        set("env/wimpy", 70);
        set("max_atman", 1000);
        set("atman", 1000);             
        set("atman_factor", 3);
        set("max_force", 1000);
        set("force", 1000);
        set("force_factor", 3);
        set("max_mana", 1000);
        set("mana", 1000);
   set("mana_factor", 3);
//      set("price_index",0);
        set_skill("parry", 200);
        set_skill("spear", 200);
        set_skill("dodge", 200);
        set_skill("force", 100);
        set_skill("duanhun-spear", 200);
        map_skill("spear","duanhun-spear");
        map_skill("parry","duanhun-spear");

        setup();
        carry_object("/obj/armor/cloth")->wear();
        carry_object("/p/residence/npc/obj/feiyunspear")->wield();
  
} 
void init()
{
        ::init();
        
        add_action("do_value", "value");
        add_action("do_pawn", "pawn");
        add_action("do_sell", "sell");
        add_action("do_redeem", "redeem");
        add_action("do_vendor_list","list");
        add_action("do_loan","loan");
        add_action("do_convert", "convert");
        add_action("do_deposit", "deposit");
        add_action("do_balance", "balance");
        add_action("do_withdraw", "withdraw");
} 
int accept_fight(object me)
{
        command("heng");
        command("say 我不懂打架的功夫，只懂降魔的功夫！");
        kill_ob(me);
        return 1;
}
       
