 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "南海大道"); 
        set("long", @LONG 
这是通往南海的一条必经之路，路面上的沙石越来越细，空气中弥漫着一股咸味， 
越往南走，咸味越明显。隐隐传来波涛拍岸的声音也越来越清晰，同时还夹杂者阵阵 
海鸥的鸣叫声。大道的东边是一家出租船具的船行，想要出海的人们都会来这里查询 
出海船只的价格。往西则是一条黑乎乎的深巷，不见尽头。
LONG 
           ); 
        set("exits", ([
             "north" : __DIR__"southsearoad", 
             "south" : __DIR__"beach", 
             "east"  : __DIR__"rentingboat" ,
            "west" : "/d/shanliu/qiongjie1",
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",10); 
        set("coor/y",-660); 
        set("coor/z",0); 
        setup(); 
       replace_program(ROOM); 
}      
