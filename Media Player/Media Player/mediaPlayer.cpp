#include "stdafx.h"
#include "mediaPlayer.h"
#include <iostream>

int mediaPlayer::songID = 0;

void mediaPlayer::displayPlaylist() {
	std::cout << "--------------------------------------\n";
	std::cout << "Song Title \t Singer \t Duration \n";
	std::cout << "--------------------------------------\n";

	std::list<song> copyPlaylist; std::list<song>::iterator copy_it;
	copyPlaylist = playlist; copy_it = copyPlaylist.begin();

	for (copy_it; copy_it != copyPlaylist.end(); copy_it++) {
		std::cout << copy_it->title << "\t" << copy_it->singer << "\t";
		std::cout << copy_it->duration << std::endl;
	}
	std::cout << "--------------------------------------\n";
}

void mediaPlayer::displaySong() {
	std::cout << it->title << "\t" << it->singer;
	std::cout << "\t" << it->duration << std::endl;
}

void mediaPlayer::openPlayer() {
	it = playlist.begin();
}

void mediaPlayer::addToPlaylist(std::string songName, std::string singer, float duration, int position) {
	s.id = ++songID; s.title = songName; s.singer = singer; s.duration = duration;
	int i; std::list<song>::iterator copy_it; copy_it = it;

	it = playlist.begin();
	if (position <= playlist.size()) {
		for (i = 0; i < position; i++) {
			it++;
		}
		playlist.insert(it, s);
	}
	else {
		playlist.push_back(s);
	}
	if (playlist.size() == 1) {
		it = playlist.begin();
	}
	else {
		it = copy_it;
	}
}

bool mediaPlayer::goToFirst() {
	if (playlist.size() == 0 || it == playlist.begin()) {
		return false;
	}
	else {
		it = playlist.begin();
		return true;
	}
}

bool mediaPlayer::goToPrev() {
	if (playlist.size() == 0 || it == playlist.begin()) {
		return false;
	}
	else {
		it--;
		return true;
	}
}

bool mediaPlayer::goToLast() {
	if (playlist.size() == 0) {
		return false;
	}
	if (++it == playlist.end()) {
		it--;
		return false;
	}
	else {
		it = playlist.end();
		it--;
		return true;
	}
}

bool mediaPlayer::goToNext() {
	if (playlist.size() == 0) {
		return false;
	}
	it++;
	if (it != playlist.end()) {
		return true;
	}
	else {
		it--;
		return false;
	}
}

void mediaPlayer::reverse() {
	playlist.reverse();
}

bool mediaPlayer::goToSong(std::string title) {
	if (playlist.size() == 0) {
		return false;
	}
	int i; std::list<song>::iterator copy_it; copy_it = it;

	it = playlist.begin();
	while (it != playlist.end()) {
		if (title.compare(it->title) == 0) {
			return true;
		}
		it++;
	}
	it = copy_it;
	return false;
}

struct removeSong {
	std::string title;
	bool operator() (const song& s) {
		return (s.title.compare(title) == 0);
	}
};

void mediaPlayer::removeFromPlaylist(std::string songTitle) {
	removeSong rs;
	rs.title = songTitle;
	playlist.remove_if(removeSong(rs));
}

bool byTitle(song first, song second) {
	return first.title < second.title;
}

bool byDuration(song first, song second) {
	return first.duration < second.duration;
}

void mediaPlayer::sortTitle() {
	playlist.sort(byTitle);
}

void mediaPlayer::sortDuration() {
	playlist.sort(byDuration);
}