//code by xiaolang@fy.sumxin.com
#include <dbase.h>
#include <move.h>
#include <name.h> 
#include <ansi.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
inherit F_MOVE;
inherit F_NAME; 
void create() {
        if(clonep(this_object())) {
                destruct(this_object());
                return notify_fail("CAN NOT CLONE STARNDARD OBJECT!\n");
        }
        set("inset",1);
} 
void init_item() { 
}  
void init() {
        add_action("do_inset", "inset");
}
int do_inset(string arg) {
	object me, stone,ob;
        string obj, item, p,name;
        int i,j,h,addjade;
        string m;      //用来取stone的属性
        int n;         //用来取伤害
        
        me = this_player();
        
        if(!arg) {
                return notify_fail("你要镶嵌什么东西。\n");
        }
        if(!sscanf(arg, "%s in %s", item,obj)) {
                return notify_fail("你要把什么镶嵌到哪里？(inset xxx in xxx)\n");
        }
        ob = present(obj, me);
        stone = present(item, me);
        
        if(!objectp(ob) || !objectp(stone)){
                return notify_fail("你没有这些东西。\n");
        }
        if( !ob->query("hole") ) {
                return notify_fail(ob->name()+"没有凹槽，你怎么镶嵌啊？\n");
        }
        if(!stone->query("inset")){
                return notify_fail(stone->name()+"不可以用来镶嵌。\n");
        }
        if( ob->query("附加/damage_type") && stone->query("附加/damage_type") && ob->query("附加/damage_type") != stone->query("附加/damage_type") ){
        	return notify_fail("你已经镶嵌了一个其他伤害类型的宝石了。\n");	
        }
        
        i=(int)stone->query("level");
        j=(int)ob->query("level");
        h=(int)ob->query("hole");
        addjade=(int)ob->query("add_jade");
        p=(string)ob->query("long");
        name=(string)ob->query("name");
        if( j <= 5 && j > 2 ){
        	if(i<2) return notify_fail(stone->name()+"配不上"+ob->name()+"了。\n");	
        }else if( j < 8 && j > 5 ){
        	if(i<5) return notify_fail(stone->name()+"配不上"+ob->name()+"了。\n");	
        }else if(j >= 8){
        	if(i<8) return notify_fail(stone->name()+"配不上"+ob->name()+"了。\n");	
        }
        message_vision(HIR+stone->name()+"化为一道金光，飞入"NOR+HIR+ob->name()+"的凹槽中。\n"NOR,this_object());
	if( h-1 == 0){
		ob->add("level",1);
		if( j+1 == 2 ) ob->set("name",name+HIM"★"NOR);
		if( j+1 == 5 ) ob->set("name",name+HIM"★"NOR);
		if( j+1 == 8 ) ob->set("name",name+HIM"★"NOR);
		if( j+1 == 9 ) ob->set("name","【"+WHT"武林至宝"NOR+"】"+name);
	}
	m=(string)stone->query("附加/damage_type");    //伤害的类型
	n=(int)stone->query("附加/damage");            //伤害的大小
	if(n){          //如果有伤害
		ob->set("附加/damage_type",m);
		ob->add("附加/damage",n);
	}
	ob->add("add_jade",1);
	ob->add("hole",-1);
	if(j+1 >= 9){
		ob->set("long","这件东西上面有"+chinese_number(addjade+1)+"颗宝石。\n旁边还有几个字："+me->name()+"\n"); 
		CHANNEL_D->do_sys_channel(
                "info",sprintf("%s，%s合成了武林至宝:%s", NATURE_D->game_time(),me->name(), ob->name()) );  
        }                       
	else
		ob->set("long","这件上面有"+chinese_number(addjade+1)+"颗宝石，"+chinese_number(h-1)+"个凹槽。\n"); 
        ob->save();
        destruct(stone);
        return 1;
}       
