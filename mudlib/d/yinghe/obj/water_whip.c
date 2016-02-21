 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit WHIP;
inherit __DIR__"yinghe_weapon"; 
void create() {
        set_name(HIC"玄冰凝魄鞭"NOR, ({ "ice whip", "whip" }) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "条");
                set("value", 1);
                set("material", "iron");
                set("long", "鞭上透着阵阵寒气。\n");
                set("wield_msg", "$N从腰间摸出一条$n握在手中。\n");
        set("unwield_msg", "$N将手中的$n束在腰间。\n");
                set("attribute", "water");
                set("yinghe_weapon", 1);
        }
        ::init_whip(90);
}  
