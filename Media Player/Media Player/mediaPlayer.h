#pragma once
#include "song.h"
#include <string>
#include <list>

class mediaPlayer {
private:
	song s;
	static int songID;
	std::list<song> playlist;
	std::list<song>::iterator it;
public:
	void openPlayer();
	void addToPlaylist(std::string songName, std::string singer, float duration, int position);
	bool goToFirst(); bool goToLast();
	bool goToPrev(); bool goToNext();
	bool goToSong(std::string title);
	void reverse();
	void sortTitle(); void sortDuration();
	void removeFromPlaylist(std::string songName);
	void displayPlaylist(); void displaySong();
};