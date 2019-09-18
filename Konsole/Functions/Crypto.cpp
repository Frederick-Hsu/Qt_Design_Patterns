#include "Crypto.h"
#include <cstdlib>

QString Crypto::shift(const QString &text, unsigned key)
{
    QString scrambled = "";
    for (int index = 0; index < text.length(); ++index)
    {
        std::srand(key);
        scrambled += (char)( ( (int)(text[index].toLatin1()) + std::rand()) % 128);
    }
    return scrambled;
}
