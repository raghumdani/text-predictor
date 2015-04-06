#ifndef EDITDISTANCE_H
#define EDITDISTANCE_H

#include <string>

class EditDistance
{
    int edit_dist;
    int sizI, sizJ;
    int** E;
    public:
    EditDistance(std::string, std::string);
    EditDistance();
    int getDistance();
    ~EditDistance();
};

#endif // EDITDISTANCE_H
