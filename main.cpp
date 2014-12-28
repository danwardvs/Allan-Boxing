#include<allegro.h>
#include<alpng.h>

BITMAP* buffer;
BITMAP* shithead;
BITMAP* shithead_beater_left;
BITMAP* shithead_beater_right;
BITMAP* blood;
BITMAP* explosion;

SAMPLE* blood_sound;
SAMPLE* explosion_sound;


//A function to streamline error reporting in file loading
void abort_on_error(const char *message){
	 set_window_title("Error!");
	 if (screen != NULL){
	    set_gfx_mode(GFX_TEXT, 0, 0, 0, 0);
	 }
	 allegro_message("%s.\n %s\n", message, allegro_error);
	 exit(-1);
}



void update(){

    bool left_punch=false;
    bool right_punch=false;
    draw_sprite(buffer,shithead,0,0);
    if(mouse_b & 1)left_punch=true;
    if(mouse_b & 2)right_punch=true;


    if(!left_punch)draw_sprite(buffer,shithead_beater_left,-10,420);
    if(left_punch)draw_sprite(buffer,shithead_beater_left,100,300);
    if(left_punch)draw_sprite(buffer,blood,300,50);
    if(left_punch)play_sample(blood_sound,125,125,1000,0);


    if(!right_punch)draw_sprite(buffer,shithead_beater_right,600,450);
    if(right_punch)draw_sprite(buffer,shithead_beater_right,500,330);
    if(right_punch)draw_sprite(buffer,explosion,200,0);
    if(right_punch)play_sample(blood_sound,125,125,1000,0);

    draw_sprite(screen,buffer,0,0);

}








void setup(){
    buffer=create_bitmap(800,600);

    if (!( shithead = load_bitmap("shithead.png", NULL)))
      abort_on_error("Cannot find shithead.png\nI hope you never find him.");
    if (!( shithead_beater_left = load_bitmap("shithead_beater_left.png", NULL)))
      abort_on_error("Cannot find shithead_beaters_left.png\nPlease find it and finish the job");
    if (!( shithead_beater_right = load_bitmap("shithead_beater_right.png", NULL)))
      abort_on_error("Cannot find shithead_beater_right.png\nPlease find it and finish the job");
    if (!( blood = load_bitmap("blood.png", NULL)))
      abort_on_error("Cannot find sblood.png\nPlease find it and finish the job");
    if (!( explosion = load_bitmap("explosion.png", NULL)))
      abort_on_error("Cannot find explosion.png\nPlease find it and finish the job");



    if (!(blood_sound = load_sample("blood_sound.wav"))){
        abort_on_error("Cannot find blood_sound.wav\nPlease check your files and try again");
    }


}






int main(){

  allegro_init();
  alpng_init();
  install_timer();
  install_keyboard();
  install_mouse();
  set_color_depth(32);


  set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800,600, 0, 0);
  install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,".");



  set_window_title("Allan is a POS");
  setup();


    while(!key[KEY_ESC]){
        update();
  	}

	return 0;
}
END_OF_MAIN()
