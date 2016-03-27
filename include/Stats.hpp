#ifndef STATS_HPP
#define STATS_HPP

class Stats{
    public:
        Stats(int hp, int mp, int attack, int defense, int level=1);
        Stats();
        ~Stats();

        void takeDamage(int damage);
        bool isAlive() const;
        int getAttackRoll() const;
        int getDefenseRoll() const;

        void levelUp();

    protected:
        int hp, mp; //Health and Mana points, respectively
        int attack, defense;
        int level;
};

#endif /* STATS_HPP */
