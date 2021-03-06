 // blade.c
// Copyright (C) 1995 - 2001, by FengYun Workshop. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
//  
#include <weapon.h>
inherit WIELD; 
void create() {
        if(clonep(this_object())) {
                destruct(this_object());
                return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
        }
} 
varargs void init_blade(int damage, int flag) {
        if(!clonep()) {
                set("weapon_prop/damage", damage);
                set("flag", (int)flag | EDGED);
                set("weapon_wielded", W_BLADE);
                set("skill_type", "blade");
                if(!query("verbs")) {
                        set("verbs", ({ "ն", "��", "��" }) );
                }
        }
        ::init_wield();
}     
