#ifndef STATS_HPP
#define STATS_HPP

class Stats{
    public:
        Stats(int maxHp, int maxMp, int attack, int defense, int level=1);
        Stats();
        ~Stats();

        void takeDamage(int damage);
        void heal(int healAmount);
        bool isAlive() const;
        int getAttackRoll() const;
        int getDefenseRoll() const;

        void levelUp();

    protected:
        int hp, mp;          // Health and Mana points, respectively
        int maxHp, maxMp;    // Maximum Health and Mana points, respectively
        int attack, defense;
        int level;
};

#endif /* STATS_HPP */
