 // blade_dan.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//
#include <ansi.h>
#include <weapon.h>
inherit DAGGER;
inherit __DIR__"yinghe_weapon";  
void create() {
        set_name(HIR"烈火荧匕首"NOR, ({ "fire dagger", "dagger" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("value", 1);
                set("material", "iron");
                set("long", "这是上面有着烈火图纹的匕首。\n");
                set("wield_msg", "$N从怀中摸出一把$n握在手中。\n");
                set("unequip_msg", "$N将手中的$N藏入怀中。\n");
                set("attribute", "fire");
                set("yinghe_weapon", 1);
        }
        ::init_dagger(90);
}      
