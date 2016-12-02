#include "mediadata.h"


void Mediadata::set_equip_type(QString _equip_type)
{
    equip_type = _equip_type;
}

int Mediadata::size()
{
    int i = 0;
    for (QVector<media_str>::iterator it = mediadata.begin(); it != mediadata.end(); ++it, i++);
    return i;
}

Mediadata::Mediadata()
{
}

Mediadata::~Mediadata()
{

}
