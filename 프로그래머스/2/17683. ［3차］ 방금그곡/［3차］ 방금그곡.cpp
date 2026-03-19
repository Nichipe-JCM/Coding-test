#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct musicrecord
{
    int duration;
    string songname;
    string totalnotes;
};

string convertnotes(const string& s){
    if (s.length() <= 1) return s;
    string str = "";
    for(int i = 0; i < s.length() ; i++)
    {
        if (s[i] == '#')
        {
            str.back() = tolower(str.back());
        }
        else str += s[i];
    }
    return str;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    string tofind = convertnotes(m);
    vector<musicrecord> musics;
    
    for(const string& s : musicinfos)
    {
        string starttime = "", endtime = "", name = "", notes = "";
        int phase = 0;
        for(char c : s)
        {
            if (c == ',') phase++;
            else
            {
                switch(phase)
                {
                    case 0:
                        if (c != ':') starttime += c;
                        break;
                    case 1:
                        if (c != ':') endtime += c;
                        break;
                    case 2:
                        name += c;
                        break;
                    case 3:
                        notes += c;
                        break;
                }
            }
        }
        
        int startint = (stoi(starttime) / 100 * 60) + (stoi(starttime) % 100);
        int endint = (stoi(endtime) / 100 * 60) + (stoi(endtime) % 100);
        int totalduration = endint - startint;
        
        string convertednotes = convertnotes(notes);
        string totalnotes = "";
        for(int i = 0; i < totalduration; i++)
        {
            totalnotes += convertednotes[i % convertednotes.length()];
        }
        
        musicrecord newmusic;
        newmusic.duration = totalduration;
        newmusic.songname = name;
        newmusic.totalnotes = totalnotes;
        musics.push_back(newmusic);
    }
    
    int maxduration = -1;
    for (const auto& m : musics)
    {
        if (m.totalnotes.find(tofind) != string::npos)
        {
            if (m.duration > maxduration)
            {
                maxduration = m.duration;
                answer = m.songname;
            }
        }
    }
    
    return answer;
}