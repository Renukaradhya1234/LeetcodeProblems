#include <string>
using namespace std;

class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            int alphabet_buffer[26] = {};
            int ransom_note_size = ransomNote.size();
            int magazine_size = magazine.size();

            for (int index = 0; index < magazine_size; index++) {
                alphabet_buffer[ magazine[index]-'a' ]++;
            }

            for (int index = 0; index < ransom_note_size; index++) {
                int mapping_index = ransomNote[index]-'a';
                if (alphabet_buffer[mapping_index] == 0) {
                    return false;
                }
                alphabet_buffer[mapping_index]--;
            }

            return true;
        }
};