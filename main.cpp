#include <allegro.h>
#include "pmask.h"
#include<string>
#include "player.h"
#include "hurdle.h"
#define bluespeed 7
 
    
    //----------------------------
    
   bool checkcol(PMASK *,PMASK *,int,int,int,int);
   
int main() {


//////////////////////////                     INTI
        install_pmask();   
        allegro_init();
	    set_color_depth(32);
	    set_gfx_mode( GFX_AUTODETECT_WINDOWED, 800, 600, 0, 0 );
        install_keyboard();
///////////////////////////                INTI	
	
BITMAP* buffer = create_bitmap( 800, 600 );	
BITMAP* mainscreen = load_bitmap("playgame.bmp",NULL);
clear_to_color( buffer, makecol(255,0,255));
draw_sprite(buffer,mainscreen,0,0);
blit( buffer, screen, 0,0, 0,0, 800, 600 );
////////////// play game///////////
int choice=0;

while(!key[KEY_ENTER]){            //menu selection 
 
 if(key[KEY_UP]){
 mainscreen = load_bitmap("playgame.bmp",NULL);                  
draw_sprite(buffer,mainscreen,0,0);
choice=0;
}
                       
if(key[KEY_DOWN]){
 mainscreen = load_bitmap("levelselect.bmp",NULL);                  
draw_sprite(buffer,mainscreen,0,0);
choice=1;
}

blit( buffer, screen, 0,0, 0,0, 800, 600 );
}// while not key enter



if(choice==1) {             
              
 while(!key[KEY_SPACE]){
 
 if(key[KEY_RIGHT]){
if(choice<3)
choice++;
}
else if(key[KEY_LEFT]){
 if(choice>1)
 choice--;                  
}                   
                       
if(choice==1){
 mainscreen = load_bitmap("lvl1.bmp",NULL);                  
draw_sprite(buffer,mainscreen,0,0);
}          

if(choice==2){
 mainscreen = load_bitmap("lvl2.bmp",NULL);                  
draw_sprite(buffer,mainscreen,0,0);
}    

if(choice==3){
 mainscreen = load_bitmap("lvl3.bmp",NULL);                  
draw_sprite(buffer,mainscreen,0,0);
}    

blit( buffer, screen, 0,0, 0,0, 800, 600 );
textprintf_ex(screen, font, 300, 30, makecol(255, 0, 0),-1,"PRESS SPACE TO SELECT");  
rest(75);
      
}//while

}// choice 1
   
   int level;
   
   if(choice==0)
   level=1;
   else
   level=choice;
   
   // Buffer /pause/ lvlcleard
   BITMAP* buffer1 = create_bitmap( 800, 600 );
   BITMAP* pausepic = load_bitmap("pause.bmp",NULL);
   BITMAP* lvlcleard = load_bitmap("lvlcleard.bmp",NULL);
     
  
  
  
   /////////////for fade out//////////////////
   BITMAP* test[8]; 
   test[0] = load_bitmap("90.bmp",NULL);
   test[1] = load_bitmap("80.bmp",NULL);
   test[2] = load_bitmap("70.bmp",NULL);
   test[3] = load_bitmap("60.bmp",NULL);
   test[4] = load_bitmap("50.bmp",NULL);
   test[5] = load_bitmap("40.bmp",NULL);
   test[6] = load_bitmap("30.bmp",NULL);
   test[7] = load_bitmap("20.bmp",NULL);
   test[7] = load_bitmap("10.bmp",NULL);
   
   //Background image
   BITMAP* background = load_bitmap("bakgr.bmp",NULL);
   
   //player object
    Player p; 
   
   //player image
   BITMAP* rb=load_bitmap("redb.bmp",NULL);
  
if(level==1){  

// player    
  


   Hurdle h,h1;

  // hurdle image for level 1 
  BITMAP* bb = load_bitmap("hurdle1.bmp",NULL); 
   
   // class setters for bitmaps
   p.setrb(rb);
   h.setbb(bb);
   h1.setbb(bb);            
 

// masks for col detectection   
 struct PMASK *mask1, *mask2, *mask3;
        mask1 = create_allegro_pmask(p.getrb());
        mask2 = create_allegro_pmask(h.getbb()); 
        mask3 = create_allegro_pmask(h1.getbb());
  


// hurdle movemts   
    h.rl=true;
    h.ll=false;

    h1.rl=false;
    h1.ll=true;
 
    

// hurdle init position    
  h.setbpos(100,0);
  h1.setbpos(170,570);
  
  //===============================================GAME LOOOOOOOOOOOOOOOOOP
  
	while (!key[KEY_ESC]) {
  bool pause=false;	
  bool pp=false; 
        
//        clear_to_color( buffer, makecol(255,255,255));
        draw_sprite(buffer,background,0,0);
      draw_sprite(buffer,p.getrb(),p.getrx(),p.getry());
       draw_sprite(buffer,h.getbb(),h.getbx(),h.getby());
      draw_sprite(buffer,h1.getbb(),h1.getbx(),h1.getby()); 
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
       textprintf_ex(screen, font, 30, 30, makecol(255, 0, 0),-1,"DEATH %d",p.showdeath());
       
//textprintf_ex(screen, font, 300, 300, makecol(255, 0, 0),-1,"LEVEL IS %d",level); 
 
   
 
 
 
  //=====================COL DETECT START=====================  
    
  h.col=checkcol(mask1,mask2,p.getrx(),p.getry(),h.getbx(),h.getby());
  h1.col=checkcol(mask1,mask3,p.getrx(),p.getry(),h1.getbx(),h1.getby());
            
    if (h.col || h1.col) { //check collision
      for(int i=0;i<7;i++){
       draw_sprite(screen,test[i],p.getrx(),p.getry()); rest(50);}       //fade out effect
         p.setback(); //set to initial position
         ++p;         //increment death
        }
    ///==================COL DETEC END======================
       
   h.setbypos(h.upperloop(h.getby()));
    h1.setbypos(h1.upperloop(h1.getby()));
 
        
        
      /// ==================  player movements   
        
        if(key[KEY_UP]){p.moveup();}
        
      if(key[KEY_DOWN]){p.movedown();}
        
        if(key[KEY_RIGHT]){p.moveright();}
        
        if(key[KEY_LEFT]){p.moveleft();}
        
        
   ///////////////// PAUSE LOOP/////////////
   if(key[KEY_P]){
      draw_sprite(buffer,pausepic,0,0); 
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
      
        pause=true;
        clear_keybuf();
        while (pause)
        {
              clear_keybuf();
              if(key[KEY_ENTER])                 
              pause=false;       
              }//while
       
       }// if P   
   ////////////  PAUSE LOOP ENDED /////////

   
   
   //  finish condition ////////
   if(p.getrx()>655){
          level++;   //level change
                     
   while(!key[KEY_ENTER]){                  
    draw_sprite(buffer,lvlcleard,0,0); 
    textprintf_ex(screen, font, 100, 100, makecol(255, 0, 0),-1,"Press Enter To Continue");
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
   }
   goto B;
   }
    
    rest(15);       
    
  clear_bitmap(buffer);

	}//while loop
destroy_pmask(mask1);
destroy_pmask(mask2);
destroy_bitmap(p.getrb());
clear_keybuf();
return 0;


}//if level == 1

B:

if(level==2){  

// player and hurdle objects   
   Player p;
   Hurdle h,h1,h2;

  // hurdle image for level 1 
  BITMAP* bb = load_bitmap("hurdle2.bmp",NULL);
  BITMAP* bba = load_bitmap("hurdle2a.bmp",NULL); 
  BITMAP* bb1 = load_bitmap("hurdle3.bmp",NULL); 
   // class setters for bitmaps
   p.setrb(rb);
   h.setbb(bb);
   h1.setbb(bba);            
   h2.setbb(bb1); 

// masks for col detectection   
 struct PMASK *mask1, *mask2, *mask3,*mask4;
        mask1 = create_allegro_pmask(p.getrb());
        mask2 = create_allegro_pmask(h.getbb()); 
        mask3 = create_allegro_pmask(h1.getbb());
        mask4 = create_allegro_pmask(h2.getbb());


// hurdle movemts   
    h.rl=true;
    h.ll=false;

    h1.rl=false;
    h1.ll=true;
 
    

// hurdle init position    
  h.setbpos(100,0);
  h1.setbpos(20,570);
  h2.setbpos(0,0);
  //===============================================GAME LOOOOOOOOOOOOOOOOOP
  
	while (!key[KEY_ESC]) {
  bool pause=false;	
  bool pp=false; 
        
        clear_to_color( buffer, makecol(255,255,255));
        draw_sprite(buffer,background,0,0);
      draw_sprite(buffer,p.getrb(),p.getrx(),p.getry());
       draw_sprite(buffer,h.getbb(),h.getbx(),h.getby());
      draw_sprite(buffer,h1.getbb(),h1.getbx(),h1.getby()); 
      draw_sprite(buffer,h2.getbb(),h2.getbx(),h2.getby());
      textprintf_ex(screen, font, 30, 30, makecol(255, 0, 0),-1,"DEATH %d",p.showdeath());
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
       
 
  //=====================COL DETECT START=====================  
    
  h.col=checkcol(mask1,mask2,p.getrx(),p.getry(),h.getbx(),h.getby());
  h1.col=checkcol(mask1,mask3,p.getrx(),p.getry(),h1.getbx(),h1.getby());
  h2.col=checkcol(mask1,mask4,p.getrx(),p.getry(),h2.getbx(),h2.getby());
            
    if (h.col || h1.col || h2.col) { 
      for(int i=0;i<7;i++){
       draw_sprite(screen,test[i],p.getrx(),p.getry()); rest(50);} //fade out
         p.setback(); 
         ++p;
        }
    ///==================COL DETEC END======================
       
   
   
   h.setbypos(h.upperloop(h.getby()));
    h1.setbypos(h1.upperloop(h1.getby()));
 
        
        
      /// ==================  player movements   
        
        if(key[KEY_UP]){p.moveup();}
        
      if(key[KEY_DOWN]){p.movedown();}
        
        if(key[KEY_RIGHT]){p.moveright();}
        
        if(key[KEY_LEFT]){p.moveleft();}
        
        
   ///////////////// PAUSE LOOP/////////////
   if(key[KEY_P]){
      draw_sprite(buffer,pausepic,0,0); 
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
      
        pause=true;
        clear_keybuf();
        while (pause)
        {
              clear_keybuf();
              if(key[KEY_ENTER])                 
              break;       
              }//while
       
       }// if P   
   ////////////  PAUSE LOOP ENDED /////////

   
   
   //  finish condition ////////
   if(p.getrx()>655){
                     level++;
   while(!key[KEY_ENTER]){                  
    draw_sprite(buffer,lvlcleard,0,0); 
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
       textprintf_ex(screen, font, 100, 100, makecol(255, 0, 0),-1,"Press Enter To Continue");
   }
   goto C;
   }
  
   

    
       
     
        
        
        
        rest(15);       
  clear_bitmap(buffer);

	}//while loop
destroy_pmask(mask1);
destroy_pmask(mask2);
destroy_bitmap(p.getrb());
clear_keybuf();
return 0;


}//if level == 2

C:

if(level==3){  

// player and hurdle objects   
   Player p;
   Hurdle h,h1,h2;

  // hurdle image for level 1 
  BITMAP* bb = load_bitmap("hurdle2.bmp",NULL);
  BITMAP* bba = load_bitmap("hurdle5.bmp",NULL); 
  BITMAP* bb1 = load_bitmap("hurdle4.bmp",NULL); 
   // class setters for bitmaps
   p.setrb(rb);
   h.setbb(bb);
   h1.setbb(bba);            
   h2.setbb(bb1); 

// masks for col detectection   
 struct PMASK *mask1, *mask2, *mask3,*mask4;
        mask1 = create_allegro_pmask(p.getrb());
        mask2 = create_allegro_pmask(h.getbb()); 
        mask3 = create_allegro_pmask(h1.getbb());
        mask4 = create_allegro_pmask(h2.getbb());


// hurdle movemts   
    h.rl=true;
    h.ll=false;

    h1.ul=false;
    h1.dl=true;
 
    

// hurdle init position    
  h.setbpos(100,0);
  h1.setbpos(90,90);
  h2.setbpos(0,0);
  //===============================================GAME LOOOOOOOOOOOOOOOOOP
  
	while (!key[KEY_ESC]) {
  bool pause=false;	
  bool pp=false; 
        
        clear_to_color( buffer, makecol(255,255,255));
        draw_sprite(buffer,background,0,0);
      draw_sprite(buffer,p.getrb(),p.getrx(),p.getry());
       draw_sprite(buffer,h.getbb(),h.getbx(),h.getby());
      draw_sprite(buffer,h1.getbb(),h1.getbx(),h1.getby()); 
      draw_sprite(buffer,h2.getbb(),h2.getbx(),h2.getby());
      textprintf_ex(screen, font, 30, 30, makecol(255, 0, 0),-1,"DEATH %d",p.showdeath());
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
       
       
//textprintf_ex(screen, font, 300, 300, makecol(255, 0, 0),-1,"LEVEL IS %d",level); 
 
   
 
 
 
  //=====================COL DETECT START=====================  
    
  h.col=checkcol(mask1,mask2,p.getrx(),p.getry(),h.getbx(),h.getby());
  h1.col=checkcol(mask1,mask3,p.getrx(),p.getry(),h1.getbx(),h1.getby());
  h2.col=checkcol(mask1,mask4,p.getrx(),p.getry(),h2.getbx(),h2.getby());
            
    if (h.col || h1.col || h2.col) { 
      for(int i=0;i<4;i++){
       draw_sprite(screen,test[i],p.getrx(),p.getry()); rest(50);}
         p.setback(); 
         ++p;
        }
        else {}   
        
        
    
    ///==================COL DETEC END======================
       
   
  // h.setbxpos(h.sideloop(h.getbx()));
   
   h.setbypos(h.upperloop(h.getby()));
  // h1.setbypos(h1.upperloop(h1.getby()));
    h1.setbxpos(h1.sideloop(h1.getbx()));
 
        
        
      /// ==================  player movements   
        
        if(key[KEY_UP]){p.moveup();}
        
      if(key[KEY_DOWN]){p.movedown();}
        
        if(key[KEY_RIGHT]){p.moveright();}
        
        if(key[KEY_LEFT]){p.moveleft();}
        
        
   ///////////////// PAUSE LOOP/////////////
   if(key[KEY_P]){
      draw_sprite(buffer,pausepic,0,0); 
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
      
        pause=true;
        clear_keybuf();
        while (pause)
        {
              clear_keybuf();
              if(key[KEY_ENTER])                 
              break;       
              }//while
       
       }// if P   
   ////////////  PAUSE LOOP ENDED /////////

   
   
   //  finish condition ////////
   if(p.getrx()>655){
   while(!key[KEY_ENTER]){                  
    draw_sprite(buffer,lvlcleard,0,0); 
       blit( buffer, screen, 0,0, 0,0, 800, 600 );
       textprintf_ex(screen, font, 100, 100, makecol(255, 0, 0),-1,"Press Enter To Continue");
   }
   break;
   }
  
   

    
       
     
        
        
        
        rest(15);       
  clear_bitmap(buffer);

	}//while loop
destroy_pmask(mask1);
destroy_pmask(mask2);
destroy_bitmap(p.getrb());
clear_keybuf();
return 0;


}//if level == 3	 


}
END_OF_MAIN()

   bool checkcol(PMASK *mask1,PMASK *mask2,int xx,int yy,int bx,int by){
        
    if(check_pmask_collision(mask1, mask2, xx,yy,bx,by )){
            return true;      
        }
        else {
                return false;
        }   
    
}
