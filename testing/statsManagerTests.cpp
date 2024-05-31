#include <gtest/gtest.h>
#include "../header/statsManager.h"

TEST(StatsManagerGetterTests, updateStatsTest) {
    int baseHP = 10; //baseHP(10)
    int baseDMG = 5; //baseDamage(5)
    int baseMR = 1; //baseMagicResist(1)
    int basePR = 1;  //basePhysicalResist(1)                  
    Weapon weapon("fists", 1, 10, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 1, 1, 2, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 1, 2);            // itemName, itemLvl, pierceValue
    StatsManager statsManager; 
    
    statsManager.updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 1 + (1 * 10) = 21
    //  currentHP   =   <= maxHP = 21
    //  currentDMG  =   characterBaseDamage + weaponDamage + (userLevel * 5) = 5 + 10 + (1 * 5) = 20
    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 0 = 1
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 2 = 3
    
    EXPECT_EQ(statsManager.getMaxHP(), 21);  // 100 base + 50 armor + 10 level*10
    EXPECT_EQ(statsManager.getCurrentHP(), 21);
    EXPECT_EQ(statsManager.getCurrentDMG(), 20);  // 20 base + 10 weapon + 5 level*1
    EXPECT_EQ(statsManager.getCurrentMR(), 1);  // 10 base + 2 armor
    EXPECT_EQ(statsManager.getCurrentPR(), 3);  // 5 base + 0 armor
}

TEST(StatsManagerMutatorTests, resetMRandPRTest) {
    int baseHP = 10; //baseHP(10)
    int baseDMG = 5; //baseDamage(5)
    int baseMR = 1; //baseMagicResist(1)
    int basePR = 1;  //basePhysicalResist(1) 
    Weapon weapon("fists", 1, 10, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 1, 1, 2, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 1, 2);            // itemName, itemLvl, pierceValue
    StatsManager statsManager; 
    
    statsManager.updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 1 + (1 * 10) = 21
    //  currentHP   =   <= maxHP = 21
    //  currentDMG  =   characterBaseDamage + weaponDamage + (userLevel * 5) = 5 + 10 + (1 * 5) = 20
    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 0 = 1
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 2 = 3
    
    statsManager.resetMRandPR(baseMR, basePR, &weapon, &armor, &trinket, 1);
    EXPECT_EQ(statsManager.getCurrentMR(), 1);  // 10 base + 2 armor
    EXPECT_EQ(statsManager.getCurrentPR(), 3);  // 5 base + 0 armor
}

TEST(StatsManagerMutatorTests, takeDamageTest) {
    int baseHP = 10; //baseHP(10)
    int baseDMG = 5; //baseDamage(5)
    int baseMR = 1; //baseMagicResist(1)
    int basePR = 1;  //basePhysicalResist(1) 
    Weapon weapon("fists", 1, 10, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 1, 1, 2, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 1, 2);            // itemName, itemLvl, pierceValue
    StatsManager statsManager; 
    
    statsManager.updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 1 + (1 * 10) = 21
    //  currentHP   =   <= maxHP = 21
    //  currentDMG  =   characterBaseDamage + weaponDamage + (userLevel * 5) = 5 + 10 + (1 * 5) = 20
    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 0 = 1
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 2 = 3
    
    statsManager.takeDamage(8, "physical");
    EXPECT_EQ(statsManager.getCurrentHP(), 21 - (8 - 3)); // currentHealthPoints - (damageAmount - currentPhysicalResistBonus)  
    statsManager.takeDamage(6, "magical"); 
    EXPECT_EQ(statsManager.getCurrentHP(), 16 - (6 - 1)); // currentHealthPoints - (damageAmount - currentMagicalResistBonus)
}

TEST(StatsManagerMutatorTests, healSelfTest) {
    int baseHP = 10; //baseHP(10)
    int baseDMG = 5; //baseDamage(5)
    int baseMR = 1; //baseMagicResist(1)
    int basePR = 1;  //basePhysicalResist(1) 
    Weapon weapon("fists", 1, 10, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 1, 1, 2, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 1, 2);            // itemName, itemLvl, pierceValue
    StatsManager statsManager; 
    
    statsManager.updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 1 + (1 * 10) = 21
    //  currentHP   =   <= maxHP = 21
    //  currentDMG  =   characterBaseDamage + weaponDamage + (userLevel * 5) = 5 + 10 + (1 * 5) = 20
    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 0 = 1
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 2 = 3
    
    statsManager.takeDamage(8, "physical");
    statsManager.healSelf(5);
    EXPECT_EQ(statsManager.getCurrentHP(), 5 + (21 - (8 - 3))); // new health = 20
    statsManager.healSelf(60);
    EXPECT_EQ(statsManager.getCurrentHP(), 21);  // Cannot exceed max HP of 21
}

TEST(StatsManagerMutatorTests, reduceMRandPRTest) {
    int baseHP = 10; //baseHP(10)
    int baseDMG = 5; //baseDamage(5)
    int baseMR = 1; //baseMagicResist(1)
    int basePR = 1;  //basePhysicalResist(1) 
    Weapon weapon("fists", 1, 10, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 1, 1, 2, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 1, 2);            // itemName, itemLvl, pierceValue
    StatsManager statsManager; 
    
    statsManager.updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 1 + (1 * 10) = 21
    //  currentHP   =   <= maxHP = 21
    //  currentDMG  =   characterBaseDamage + weaponDamage + (userLevel * 5) = 5 + 10 + (1 * 5) = 20
    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 0 = 1
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 2 = 3
    
    statsManager.reduceMR(5);
    EXPECT_EQ(statsManager.getCurrentMR(), 0);  // 1 - 5 = 0 (cannot be less than 0)
    statsManager.reducePR(2);
    EXPECT_EQ(statsManager.getCurrentPR(), 1);  // 3 - 2 = 1
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}