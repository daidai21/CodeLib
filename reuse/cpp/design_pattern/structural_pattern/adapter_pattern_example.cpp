#include <iostream>
#include <string>


class MediaPlayer {
 public:
  virtual void play(std::string audio_type, std::string file_name) = 0;
};

class AdvancedMediaPlayer {
 public:
  virtual void play_vlc(std::string file_name) = 0;
  virtual void play_mp4(std::string file_name) = 0;
};

class VlcPlayer : public AdvancedMediaPlayer {
 public:
  virtual void play_vlc(std::string file_name) {
    std::cout << "Playing vlc file. Name: " << file_name << std::endl;
  }

  virtual void play_mp4(std::string file_name) { }
};

class Mp4Player : public AdvancedMediaPlayer {
 public:
  virtual void play_vlc(std::string file_name) { }

  virtual void play_mp4(std::string file_name) {
    std::cout << "Playing mp4 file. Name: " << file_name << std::endl;
  }
};

class MediaAdapter : public MediaPlayer {
 public:
  MediaAdapter(std::string audio_type) {
    if (audio_type == "vlc") {
      this->advance_music_player = new VlcPlayer();
    } else if (audio_type == "mp4") {
      this->advance_music_player = new Mp4Player();
    }
  }

  virtual void play(std::string audio_type, std::string file_name) {
    if (audio_type == "vlc") {
      this->advance_music_player->play_vlc(file_name);
    } else if (audio_type == "mp4") {
      this->advance_music_player->play_mp4(file_name);
    }
  }
 private:
  AdvancedMediaPlayer* advance_music_player;
};

class AudioPlayer : public MediaPlayer {
 public:
  virtual void play(std::string audio_type, std::string file_name) {
    if (audio_type == "mp3") {
      std::cout << "Playing mp3 file. Name: " << file_name << std::endl;
    } else if (audio_type == "vlc" || audio_type == "mp4") {
      this->media_adapter = new MediaAdapter(audio_type);
      this->media_adapter->play(audio_type, file_name);
    } else {
      std::cout << "Invalid media. " << audio_type << " format not supported" << std::endl;
    }
  }

 private:
  MediaPlayer* media_adapter;
};


int main() {
  AudioPlayer* audio_player = new AudioPlayer();

  audio_player->play("mp3", "beyond the horizon.mp3");
  audio_player->play("mp4", "alone.mp4");
  audio_player->play("vlc", "far far away.vlc");
  audio_player->play("avi", "mind me.avi");

  delete audio_player;

  return 0;
}

