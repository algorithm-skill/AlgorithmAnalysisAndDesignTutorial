#define MULTIPLIER 0x015B4F64L;
#define INCREMENT 1;
static unsigned long seed;

void random_seed(unsigned long d)
{
    if(d == 0)
        seed = time(0);
    else
        seed = d;
}

unsigned int random(unsigned long low, unsigned long high)
{
    seed = MULTIPLIER * seed + INCREMENT;
    return ((seed>>16) % (high - low) + low);
}

