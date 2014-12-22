#include<allegro.h>
#include<alpng.h>

BITMAP* buffer;
BITMAP* shithead;
BITMAP* shithead_beater_left;
BITMAP* shithead_beater_right;


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

    bool left_punch;
    bool right_punch;
    draw_sprite(buffer,shithead,0,0);
    draw_sprite(buffer,shithead_beater_left,-10,420);
    draw_sprite(buffer,shithead_beater_right,600,450);
    if(mouse_b & 1)


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
