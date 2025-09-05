#include <stdbool.h>

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
bool isBadVersion(int version);

int firstBadVersion(int n) {
    unsigned int start_version = 1;
    unsigned int last_version = n;
    unsigned int mid_version = 0;
    bool version_status = false;
    unsigned int first_bad_version = 0;

    while (start_version <= last_version) {
        mid_version = start_version + (last_version-start_version) / 2;
        version_status = isBadVersion(mid_version);

        if (version_status) {
            first_bad_version = mid_version;
            last_version = mid_version-1;
        } else {
            start_version = mid_version+1;
        }
    }

    return first_bad_version;
}