#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../header/item.h"
#include "../header/armor.h"

TEST(getterTestsHelmet, getNameTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    std::string testName = testArmor.getName();

    EXPECT_EQ(testName, "helmet");
}

TEST(getterTestsHelmet, getTypeTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    std::string testType = testArmor.getType();
    EXPECT_EQ(testType, "armor");
}


TEST(getterTestsHelmet, getLevelTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int testLevel = testArmor.getLevel();

    EXPECT_EQ(testLevel, 5);
}

TEST(getterTestsHelmet, getHealthTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int test = testArmor.getHealth();

    EXPECT_EQ(test, 5);
}
TEST(getterTestsHelmet, getPhyResTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int test = testArmor.getPhyRes();

    EXPECT_EQ(test, 5);
}
TEST(getterTestsHelmet, getMagResTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int test = testArmor.getMagRes();

    EXPECT_EQ(test, 5);
}
TEST(calcTestHelmet, calcPhyDamageTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int testDamage = testArmor.calcPhyDamage(10);

    EXPECT_EQ(testDamage, 7);
}

TEST(calcTestHelmet, calcMagDamageTest) {
    Armor testArmor("helmet", 5, 5, 5, 5);
    int testDamage = testArmor.calcMagDamage(10);

    EXPECT_EQ(testDamage, 7);
}
//******************************************************
#include "../header/screens/screen.h"

TEST(characterSelectTests, constructorTest){
    EXPECT_NO_THROW({CharacterSelect test("", new User());});
}

TEST(characterSelectTests, displayTest){
    CharacterSelect test("characterSelectScreen.txt", new User());
    EXPECT_NO_THROW({test.displayScreen();});
}

TEST(characterSelectTests, testOption1){
    User* testUser = new User();
    bool dummyRunning = true;
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(1, dummyRunning);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Warrior");
}

TEST(characterSelectTests, testOption2){
    User* testUser = new User();
    bool dummyRunning = true;
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(2, dummyRunning);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Mage");
}

TEST(characterSelectTests, testOption3){
    User* testUser = new User();
    bool dummyRunning = true;
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(3, dummyRunning);
    EXPECT_NE(testReturn, &test);
    EXPECT_EQ(testUser->getCharacterClass()->getClassName(), "Rogue");
}

TEST(characterSelectTests, testOtherOption){
    User* testUser = new User();
    bool dummyRunning = true;
    CharacterSelect test("characterSelectScreen.txt", testUser);
    Screen* testReturn = test.processOption(0, dummyRunning);
    EXPECT_EQ(testReturn, &test);
}
//******************************************************
#include "../header/character.h"
using ::testing::Return;
using ::testing::InSequence;

class SpellChildStub: public Spell{
    public:
        SpellChildStub(){}
        MOCK_METHOD((void), doSpell, (int&, int&, int, int&, Enemy*), (override));
};

TEST(getterTestsCharacter, getHpTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    int testHP = char1.getBaseHP();
    EXPECT_EQ(testHP, 1);
}

TEST(getterTestsCharacter, getDamageTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    int testDamage = char1.getBaseDamage();
    EXPECT_EQ(testDamage, 1);
}

TEST(getterTestsCharacter, getPRTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    int testPR = char1.getBasePhysicalResist();
    EXPECT_EQ(testPR, 1);
}

TEST(getterTestsCharacter, getMRTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    int testMR = char1.getBaseMagicResist();
    EXPECT_EQ(testMR, 1);
}

TEST(getterTestsCharacter, getClassNameTest){
    Character char1(1,1,1,1,"class1", nullptr, nullptr, nullptr);
    std::string testName = char1.getClassName();
    EXPECT_EQ(testName, "class1");
}

TEST(getterTestsCharacter, getFirstSpellTest){
    Spell* spellTester = new SpellChildStub();
    Character char1(1,1,1,1,"class1", spellTester, nullptr, nullptr);
    Spell* returnTester = char1.getFirstSpell();
    EXPECT_EQ(spellTester, returnTester);
}

TEST(getterTestsCharacter, getSecondSpellTest){
    Spell* spellTester = new SpellChildStub();
    Character char1(1,1,1,1,"class1", nullptr, spellTester, nullptr);
    Spell* returnTester = char1.getSecondSpell();
    EXPECT_EQ(spellTester, returnTester);
}

TEST(getterTestsCharacter, getThirdSpellTest){
    Spell* spellTester = new SpellChildStub();
    Character char1(1,1,1,1,"class1", nullptr, nullptr, spellTester);
    Spell* returnTester = char1.getThirdSpell();
    EXPECT_EQ(spellTester, returnTester);
}
//******************************************************
#include "../header/screens/screen.h"

TEST(cityTests, noThrowDisplayTest){
    User* testUser = new User();
    Screen* testCity = new City("cityScreen.txt", testUser);
    EXPECT_NO_THROW({testCity->displayScreen();});
}

TEST(cityTests, testOptionOne){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* testCity = new City("cityScreen.txt", testUser);
    City* testCity2 = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(1, dummyRunning);
    EXPECT_EQ(testCity, resultCity);
    resultCity = testCity2->processOption(1, dummyRunning);
    EXPECT_TRUE(testCity2->getTavernUsed());
}

TEST(cityTests, testOption2){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* testCity = new City("cityScreen.txt", testUser);
    City* testCity2 = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(2, dummyRunning);
    EXPECT_EQ(testCity, resultCity);
    testUser->getGold() += 1000;
    resultCity = testCity2->processOption(2, dummyRunning);
    EXPECT_EQ(testCity2->getCityWeapon(), nullptr);
}

TEST(cityTests, testOption3){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* testCity = new City("cityScreen.txt", testUser);
    City* testCity2 = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(3, dummyRunning);
    EXPECT_EQ(testCity, resultCity);
    testUser->getGold() += 1000;
    resultCity = testCity2->processOption(3, dummyRunning);
    EXPECT_EQ(testCity2->getCityArmor(), nullptr);
}

TEST(cityTests, testOption4){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* testCity = new City("cityScreen.txt", testUser);
    City* testCity2 = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(4, dummyRunning);
    EXPECT_EQ(testCity, resultCity);
    testUser->getGold() += 1000;
    resultCity = testCity2->processOption(4, dummyRunning);
    EXPECT_EQ(testCity2->getCityTrinket(), nullptr);
}

TEST(cityTests, testOption5){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(5, dummyRunning);
    ItemManager* userItemManager = testUser->getItemManager();
    EXPECT_EQ(testCity, resultCity);
    EXPECT_TRUE(userItemManager->getWeaponInventory()->size() == 0 && userItemManager->getArmorInventory()->size() == 0 && userItemManager->getTrinketInventory()->size() == 0);
}

TEST(cityTests, testOption6){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* testCity = new City("cityScreen.txt", testUser);
    Screen* resultCity = testCity->processOption(6, dummyRunning);
    EXPECT_NE(testCity, resultCity);
}
//******************************************************
#include "../header/screens/screen.h"

TEST(combatTests, constructorTest){
    User* testUser = new User();
    EXPECT_NO_THROW({
        Screen* testCombat = new Combat("combatScreen.txt", testUser);
    }); 
}

TEST(combatTests, displayTest){
    User* testUser = new User();
    testUser->getCharacterClass() = new Warrior();
    Screen* testCombat = new Combat("combatScreen.txt", testUser);
    EXPECT_NO_THROW({
        testCombat->displayScreen();
    });
}

TEST(combatTests, testOptionOne){
    User* testUser = new User();
    bool dummyRunning = true;
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(1, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "you attacked the enemy with your weapon");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionTwo){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() = new Warrior();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(2, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You used Slam on the enemy!");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionThreeLowLvl){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() =  new Warrior();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(3, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You tried to use Shatter on the enemy, but your level isn't high enough!");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionThreeHighLvl){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() =  new Warrior();
    testUser->levelUp();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(3, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You used Shatter on the enemy!");
    EXPECT_EQ(equalTester, resultScreen);
}
TEST(combatTests, testOptionFourLowLvl){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() =  new Warrior();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(4, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You tried to use Bludgeon on the enemy, but your level isn't high enough!");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionFourHighLvl){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() = new Warrior();
    testUser->levelUp();
    testUser->levelUp();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(4, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You used Bludgeon on the enemy!");
    EXPECT_EQ(equalTester, resultScreen);
}

TEST(combatTests, testOptionFive){
    User* testUser = new User();
    bool dummyRunning = true;
    testUser->getCharacterClass() =  new Warrior();
    Combat* testCombat = new Combat("combatScreen.txt", testUser);
    Screen* equalTester = testCombat;
    Screen* resultScreen = testCombat->processOption(5, dummyRunning);
    EXPECT_EQ(testCombat->getUserLastMoveStr(), "You tried to flee and failed!");
    EXPECT_EQ(equalTester, resultScreen);
}
//******************************************************
#include "../header/encounterManager.h"

TEST(encounterManagerTests, defaultConstructorTest)
{
    EncounterManager encounterManager;
    EXPECT_EQ(encounterManager.getEncounterCount(), 0);
}

TEST(encounterManagerTests, parameterizedConstructorTest)
{
    EncounterManager encounterManager(1);
    EXPECT_EQ(encounterManager.getEncounterCount(), 1);
}

TEST(encounterManagerTests, resetEncounterTest)
{
    EncounterManager encounterManager(2);
    encounterManager.resetEncounterCount();
    EXPECT_EQ(encounterManager.getEncounterCount(), 0);
}

TEST(EncounterManagerTests, incrementEncounterTest)
{
    EncounterManager encounterManager;
    encounterManager.incrementEncounterCount();
    EXPECT_EQ(encounterManager.getEncounterCount(), 1);
}

TEST(EncounterManagerTests, getEncounterCount_ThrowTest)
{
    EncounterManager encounterManager;
    EXPECT_NO_THROW(encounterManager.getEncounterCount());
}
//******************************************************
#include "../header/enemy.h"

class MockEnemy: public Enemy{
    public: 
    MockEnemy(int lvl, int hp, int mxhp, int dmg, int mr, int pr, bool isdead, std::string name):Enemy(lvl, hp, mxhp, dmg, mr, pr, isdead, name){}
    MOCK_METHOD((void), calculateTurn, (StatsManager*), (override));
};

TEST(enemyGetterTests, getLevelTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getLevel(), 1);
}

TEST(enemyGetterTests, getHealthTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getHealth(), 1);
}

TEST(enemyGetterTests, getMaxHealthTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getMaxHealth(), 1);
}

TEST(enemyGetterTests, getDamageTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getDamage(), 1);
}

TEST(enemyGetterTests, getMagicResistTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getMagicResist(), 1);
}

TEST(enemyGetterTests, getPhysicalResistTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getPhysicalResist(), 1);
}

TEST(enemyGetterTests, getStatusTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_TRUE(!(monster1.getStatus()));
}

TEST(enemyGetterTests, getNameTest)
{
    MockEnemy monster1(1, 1, 1, 1, 1, 1, false, "Bill");
    EXPECT_EQ(monster1.getName(), "Bill");
}
//******************************************************
#include "../header/game.h"

TEST(gameTests, constructorTest){
    EXPECT_NO_THROW({
        Game game1();
    });
}
//******************************************************
#include "../header/goblinBoss.h"
#include "../header/statsManager.h"

TEST(getterTestsGoblinBoss, constructorInitializationTest) 
{
    GoblinBoss goblinBoss;

    EXPECT_EQ(goblinBoss.getLevel(), 5);
    EXPECT_EQ(goblinBoss.getHealth(), 60);
    EXPECT_EQ(goblinBoss.getMaxHealth(), 60);
    EXPECT_EQ(goblinBoss.getDamage(), 5);
    EXPECT_EQ(goblinBoss.getMagicResist(), 10);
    EXPECT_EQ(goblinBoss.getPhysicalResist(), 15);
    EXPECT_EQ(goblinBoss.getName(), "Commander Joe");
}

TEST(GoblinBossTest, CalculatePhaseOneTurnTest) 
{
    GoblinBoss goblinBoss; 
    StatsManager* statsManager = new StatsManager();
    Weapon weapon("fists", 0, 0, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 0, 0, 0, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 0, 0);            // itemName, itemLvl, pierceValue
    statsManager->updateStats(1,10,1,1, &weapon, &armor, &trinket, 1); 

    goblinBoss.dealDamage(15); //should put hp down to 45, which is above 30

    goblinBoss.calculateTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 12);
    EXPECT_EQ(goblinBoss.getHealth(), 55);

    delete statsManager;
}

TEST(GoblinBossTest, CalculatePhaseTwoTurnTest_HighHP) 
{
    GoblinBoss goblinBoss;
    StatsManager* statsManager = new StatsManager();
    Weapon weapon("fists", 0, 0, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 0, 0, 0, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 0, 0);            // itemName, itemLvl, pierceValue
    statsManager->updateStats(1,10,1,1, &weapon, &armor, &trinket, 1); 

    goblinBoss.dealDamage(35); //should put hp down to 25, which is below 30

    goblinBoss.calculateTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 2);
    EXPECT_EQ(goblinBoss.getHealth(), 45);

    delete statsManager;
}
TEST(GoblinBossTest, CalculatePhaseTwoTurnTest_LowHP) 
{
    GoblinBoss goblinBoss;
    StatsManager* statsManager = new StatsManager();
    Weapon weapon("fists", 0, 0, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 0, 0, 0, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 0, 0);            // itemName, itemLvl, pierceValue
    statsManager->updateStats(1,50,1,1, &weapon, &armor, &trinket, 1); 

    int initialHP = statsManager->getCurrentHP();

    goblinBoss.dealDamage(55);

    goblinBoss.calculateTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 10);
    EXPECT_EQ(statsManager->getCurrentPR(), 0);
    EXPECT_EQ(statsManager->getCurrentMR(), 0);
    EXPECT_EQ(goblinBoss.getHealth(), 55);
    
    delete statsManager;
}
//******************************************************
#include "../header/goblin.h"
#include "../header/character.h"

TEST(getterTestsGoblin, constructorInitializationTest)
{
    Goblin goblin;

    EXPECT_EQ(goblin.getLevel(), 2);
    EXPECT_EQ(goblin.getHealth(), 15);
    EXPECT_EQ(goblin.getMaxHealth(), 15);
    EXPECT_EQ(goblin.getDamage(), 3);
    EXPECT_EQ(goblin.getMagicResist(), 5);
    EXPECT_EQ(goblin.getPhysicalResist(), 5);
    EXPECT_EQ(goblin.getName(), std::string("Goblin").c_str());
}

TEST(damageTests, damage_heal_Test) 
{
    Goblin goblin;                    
    StatsManager* statsManager = new StatsManager(); 
    Weapon weapon("fists", 0, 0, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 0, 0, 0, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 0, 0);            // itemName, itemLvl, pierceValue
    statsManager->updateStats(1,10,1,1, &weapon, &armor, &trinket, 1); 
    
    // Pre-Turn Stats
    EXPECT_EQ(statsManager->getCurrentHP(), 20);
    EXPECT_EQ(statsManager->getCurrentDMG(), 6);
    EXPECT_EQ(statsManager->getCurrentMR(), 1);
    EXPECT_EQ(statsManager->getCurrentPR(), 1);
    
    goblin.dealDamage(5);
    
    goblin.calculateTurn(statsManager);
    
    // Post-Turn Stats
    EXPECT_EQ(statsManager->getCurrentHP(), 18);
    EXPECT_EQ(goblin.getHealth(), 13); 

    delete statsManager;

}
//******************************************************
#include "../header/screens/screen.h"

TEST(mainMenuTests, constructorTest){
    EXPECT_NO_THROW({
        InGameMenu* menuTest = new InGameMenu("gameMenuScreen.txt", new User());
    });
}

TEST(mainMenuTests, displayTest){
    User* testUser = new User();
    InGameMenu* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    EXPECT_NO_THROW({
        menuTest->displayScreen();
    });
}

TEST(mainMenuTests, processOptionOneTest){
    User* testUser = new User();
    bool testBool = true;
    Screen* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    Screen* testScreen = menuTest->processOption(1, testBool);
    EXPECT_NE(testScreen, menuTest);
}

TEST(mainMenuTests, processOptionTwoTest){
    User* testUser = new User();
    bool testBool = true;
    Screen* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    Screen* testScreen = menuTest->processOption(2, testBool);
    EXPECT_NE(testScreen, menuTest);
}

TEST(mainMenuTests, processOptionThreeTest){
    User* testUser = new User();
    bool testBool = true;
    Screen* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    Screen* testScreen = menuTest->processOption(3, testBool);
    EXPECT_NE(testScreen, menuTest);
}

TEST(mainMenuTests, processOptionOtherTest){
    User* testUser = new User();
    bool testBool = true;
    Screen* menuTest = new InGameMenu("gameMenuScreen.txt", testUser);
    Screen* testScreen = menuTest->processOption(4, testBool);
    EXPECT_EQ(testScreen, menuTest);
}
//******************************************************
#include "../header/screens/screen.h"

TEST(inventoryTests, displayTest){
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_NO_THROW(inventory->displayScreen());
}

TEST(inventoryTests, processOptionOne){
    bool dummyRunning = true;
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Weapon* newWeapon = new Weapon();
    items->getWeaponInventory()->push_back(newWeapon);
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(1, dummyRunning), inventory);
    EXPECT_EQ(items->getEquippedWeapon(), newWeapon);
}

TEST(inventoryTests, processOptionTwo){
    bool dummyRunning = true;
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Armor* newArmor = new Armor();
    items->getArmorInventory()->push_back(newArmor);
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(2, dummyRunning), inventory);
    EXPECT_EQ(items->getEquippedArmor(), newArmor);
}


TEST(inventoryTests, processOptionThree){
    bool dummyRunning = true;
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Trinket* newTrinket = new Trinket();
    items->getTrinketInventory()->push_back(newTrinket);
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_EQ(inventory->processOption(3, dummyRunning), inventory);
    EXPECT_EQ(items->getEquippedTrinket(), newTrinket);
}

TEST(inventoryTests, processOptionFour){
    bool dummyRunning = true;
    StatsManager* stats = new StatsManager();
    ItemManager* items = new ItemManager();
    EncounterManager* encounters = new EncounterManager();
    Character* character = new Character();
    User* user = new User(1,1, encounters, character, stats, items);
    Screen* inventory = new Inventory("inventoryScreen.txt", user);
    EXPECT_NE(inventory->processOption(4, dummyRunning), inventory);
}
//******************************************************
#include "../header/user.h"
#include "../header/itemManager.h"

TEST(itemManagerConstructor, getterFunctionTests) {
    std::vector<Weapon*>* weapons = new std::vector<Weapon*>;
    std::vector<Armor*>* armors = new std::vector<Armor*>;
    std::vector<Trinket*>* trinkets = new std::vector<Trinket*>;
    Weapon* w = new Weapon("",0, 0, "");
    Armor* a = new Armor("", 0,0,0,0);
    Trinket* t = new Trinket("",0,0);

    ItemManager* im = new ItemManager(weapons, armors, trinkets, w, a, t);

    EXPECT_EQ(im->getWeaponInventory(), weapons);
    EXPECT_EQ(im->getEquippedWeapon(), w);
    EXPECT_EQ(im->getEquippedArmor(), a);
    EXPECT_EQ(im->getEquippedTrinket(), t);
}
//******************************************************
#include "../header/item.h"
using std::string;

class MockItem: public Item{
  public:
  MockItem(string name, int level, string type): Item(name, level, type){}
    MOCK_METHOD((int), calcValue, (), (override));
};

TEST(ItemTests, constructorTests)
{
    EXPECT_NO_THROW({
      MockItem testItem("name", 2, "weapon");
    });
}

TEST(ItemTests, getNameTest){
  MockItem testItem("name", 2, "weapon");
  EXPECT_EQ(testItem.getName(), "name");
}

TEST(ItemTests, getLevelTest){
  MockItem testItem("name", 2, "weapon");
  EXPECT_EQ(testItem.getLevel(), 2);
}

TEST(ItemTests, getTypeTest){
  MockItem testItem("name", 2, "weapon");
  EXPECT_EQ(testItem.getType(), "weapon");
}
//******************************************************
#include "../header/mage.h"

TEST(mageGetterTests, getHpTest){
    Mage mage;
    int testHP = mage.getBaseHP();
    EXPECT_EQ(testHP, 7);
}

TEST(mageGetterTests, getDamageTest){
    Mage mage;
    int testDamage = mage.getBaseDamage();
    EXPECT_EQ(testDamage, 12);
}

TEST(mageGetterTests, getPRTest){
    Mage mage;
    int testPR = mage.getBasePhysicalResist();
    EXPECT_EQ(testPR, 5);
}

TEST(mageGetterTests, getMRTest){
    Mage mage;
    int testMR = mage.getBaseMagicResist();
    EXPECT_EQ(testMR, 5);
}

TEST(mageGetterTests, getClassNameTest){
    Mage mage;
    std::string testName = mage.getClassName();
    EXPECT_EQ(testName, std::string("Mage").c_str());;
}

TEST(mageSpellGetterTests, getFirstClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("ArcaneBlast").c_str());;
}

TEST(mageSpellGetterTests, getSecondClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("LifeLeech").c_str());;
}

TEST(mageSpellGetterTests, getThirdClassNameTest){
    Mage mage;
    Spell* returnedSpell = mage.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Incinerate").c_str());;
}

TEST(mageSpellGetterTests, getFirstSpellLevelThreshold){
    Mage mage;
    Spell* returnedSpell = mage.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 1);
}

TEST(mageSpellGetterTests, getSecondSpellLevelThreshold){
    Mage mage;
    Spell* returnedSpell = mage.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 2);
}

TEST(mageSpellGetterTests, getThirdSpellLevelThreshold){
    Mage mage;
    Spell* returnedSpell = mage.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 3);
}

TEST(mageSpellTests, testFirstDoSpell){
    Mage mage;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(mage.getFirstSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(mageSpellTests, testSecondDoSpell){
    Mage mage;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(mage.getSecondSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(mageSpellTests, testThirdDoSpell){
    Mage mage;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(mage.getFirstSpell()->doSpell(hp, dmg, 1, gold, enemy););
}
//******************************************************
#include "../header/orcBoss.h"
#include "../header/statsManager.h"

TEST(getterTestsOrcBoss, constructorInitializationTest) {
    OrcBoss orcBoss;

    EXPECT_EQ(orcBoss.getLevel(), 8);
    EXPECT_EQ(orcBoss.getHealth(), 100);
    EXPECT_EQ(orcBoss.getMaxHealth(), 100);
    EXPECT_EQ(orcBoss.getDamage(), 21);
    EXPECT_EQ(orcBoss.getMagicResist(), 3);
    EXPECT_EQ(orcBoss.getPhysicalResist(), 14);
    EXPECT_EQ(orcBoss.getName(), "General Bob");
}

TEST(OrcBossTest, CalculatePhaseOneTurnTest) {
    OrcBoss* orcBoss = new OrcBoss();
    StatsManager* statsManager = new StatsManager();
    Weapon* testWeapon = new Weapon();
    Armor* testArmor = new Armor();
    Trinket* testTrinket = new Trinket();
    statsManager->updateStats(1,1,1,1, testWeapon, testArmor, testTrinket, 1);

    int initialHP = statsManager->getCurrentHP();
    int initialPR = statsManager->getCurrentPR();

    orcBoss->calculatePhaseOneTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 0);
    EXPECT_EQ(statsManager->getCurrentPR(), 0);

    delete orcBoss;
    delete statsManager;
}

TEST(OrcBossTest, CalculatePhaseTwoTurnTest) {
    OrcBoss* orcBoss = new OrcBoss();
    StatsManager* statsManager = new StatsManager();
    Weapon* testWeapon = new Weapon();
    Armor* testArmor = new Armor();
    Trinket* testTrinket = new Trinket();
    statsManager->updateStats(1,1,1,1, testWeapon, testArmor, testTrinket, 1);
    int initialHP = statsManager->getCurrentHP();
    int initialPR = statsManager->getCurrentPR();
    int initialMR = statsManager->getCurrentMR();

    orcBoss->calculatePhaseTwoTurn(statsManager);

    EXPECT_EQ(statsManager->getCurrentHP(), 0);
    EXPECT_EQ(statsManager->getCurrentPR(), 0);
    EXPECT_EQ(statsManager->getCurrentMR(), 0);
    
    delete orcBoss;
    delete statsManager;
}
//******************************************************
#include "../header/orc.h"
#include "../header/character.h"

TEST(getterTestsOrc, constructorInitializationTest) {
    Orc orc;

    EXPECT_EQ(orc.getLevel(), 3);
    EXPECT_EQ(orc.getHealth(), 60);
    EXPECT_EQ(orc.getMaxHealth(), 60);
    EXPECT_EQ(orc.getDamage(), 8);
    EXPECT_EQ(orc.getMagicResist(), 3);
    EXPECT_EQ(orc.getPhysicalResist(), 8);
    EXPECT_EQ(orc.getName(), std::string("Orc").c_str());
}

TEST(damageTests, damageEffectsTest) {
    Orc orc;
    Character character;                        // baseHP(10), baseDamage(5), basePhysicalResist(1), baseMagicResist(1)
    Weapon weapon("fists", 1, 10, "physical");  // itemName, itemLvl, dmg, dmgType
    Armor armor("cloth", 1, 1, 2, 0);           // itemName, itemLvl, healthBonus, physicalResist, magicalResist
    Trinket trinket("locket", 1, 2);            // itemName, itemLvl, pierceValue
    StatsManager statsManager; 
    
    statsManager.updateStats(character.getBaseDamage(), character.getBaseHP(), character.getBaseMagicResist(), character.getBasePhysicalResist(), &weapon, &armor, &trinket, 1);
    
    // Pre-Turn Stats
    EXPECT_EQ(statsManager.getCurrentHP(), 21);
    EXPECT_EQ(statsManager.getCurrentDMG(), 20);
    EXPECT_EQ(statsManager.getCurrentMR(), 1);
    EXPECT_EQ(statsManager.getCurrentPR(), 3);
    
    orc.calculateTurn(&statsManager);
    
    // Post-Turn Stats
    EXPECT_EQ(statsManager.getCurrentHP(), 0);
    EXPECT_EQ(statsManager.getCurrentDMG(), 20); 
    EXPECT_EQ(statsManager.getCurrentMR(), 1); 
    EXPECT_EQ(statsManager.getCurrentPR(), 3-2); 
}
//******************************************************

#include "../header/enemy.h"
#include "../header/pirate.h"
#include "../header/statsManager.h"
#include "../header/weapon.h"
#include "../header/trinket.h"
#include "../header/armor.h"
#include "../header/character.h"


TEST(getterTestsPirate, pirateInheritanceTest) {
    Pirate pirate(5, 5, 5, 5, 5, 5, false, "Jack Sparrow");

    ASSERT_EQ(pirate.getLevel(), 5);
    ASSERT_EQ(pirate.getHealth(), 5);
    ASSERT_EQ(pirate.getMaxHealth(), 5);
    ASSERT_EQ(pirate.getDamage(), 5);
    ASSERT_EQ(pirate.getMagicResist(), 5);
    ASSERT_EQ(pirate.getPhysicalResist(), 5);
    ASSERT_EQ(pirate.getStatus(), false);
    ASSERT_EQ(pirate.getName(), "Jack Sparrow");
}


TEST(calcTests, pirateCalcTurnTest) {
    Pirate pirate(3, 3, 3, 3, 3, 3, false, "Jack Sparrow");

    Character character;
    int baseDMG = character.getBaseDamage();
    int baseHP = character.getBaseHP();
    int baseMR = character.getBaseMagicResist();
    int basePR = character.getBasePhysicalResist();
    Weapon weapon("knife", 5, 5, "physical");
    Armor armor("helmet", 1, 5, 1, 1);           
    Trinket trinket("locket", 5, 5);  
    StatsManager* sm = new StatsManager();

    sm->updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 5 + (1 * 10) = 25

    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 5 = 6
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 1 = 2

    pirate.calculateTurn(sm);
    EXPECT_EQ(sm->getCurrentHP(), 24);
}
//******************************************************
#include "../header/rogue.h"

TEST(rogueGetterTests, getHpTest){
    Rogue rogue;
    int testHP = rogue.getBaseHP();
    EXPECT_EQ(testHP, 10);
}

TEST(rogueGetterTests, getDamageTest){
    Rogue rogue;
    int testDamage = rogue.getBaseDamage();
    EXPECT_EQ(testDamage, 12);
}

TEST(rogueGetterTests, getPRTest){
    Rogue rogue;
    int testPR = rogue.getBasePhysicalResist();
    EXPECT_EQ(testPR, 3);
}

TEST(rogueGetterTests, getMRTest){
    Rogue rogue;
    int testMR = rogue.getBaseMagicResist();
    EXPECT_EQ(testMR, 2);
}

TEST(rogueGetterTests, getClassNameTest){
    Rogue rogue;
    std::string testName = rogue.getClassName();
    EXPECT_EQ(testName, "Rogue");
}

TEST(rogueSpellGetterTests, getFirstClassNameTest){
    Rogue rogue;
    Spell* returnedSpell = rogue.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Backstab").c_str());
}

TEST(rogueSpellGetterTests, getSecondClassNameTest){
    Rogue rogue;
    Spell* returnedSpell = rogue.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("PickPocket").c_str());
}

TEST(rogueSpellGetterTests, getThirdClassNameTest){
    Rogue rogue;
    Spell* returnedSpell = rogue.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Cutthroat").c_str());
}

TEST(rogueSpellGetterTests, getFirstSpellLevelThreshold){
    Rogue rogue;
    Spell* returnedSpell = rogue.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 1);
}

TEST(rogueSpellGetterTests, getSecondSpellLevelThreshold){
    Rogue rogue;
    Spell* returnedSpell = rogue.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 2);
}

TEST(rogueSpellGetterTests, getThirdSpellLevelThreshold){
    Rogue rogue;
    Spell* returnedSpell = rogue.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 3);
}

TEST(rogueSpellTests, testFirstDoSpell){
    Rogue rogue;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(rogue.getFirstSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(rogueSpellTests, testSecondDoSpell){
    Rogue rogue;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(rogue.getSecondSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(rogueSpellTests, testThirdDoSpell){
    Rogue rogue;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(rogue.getThirdSpell()->doSpell(hp, dmg, 1, gold, enemy););
}
//******************************************************
#include "../header/enemy.h"
#include "../header/royalGuard.h"
#include "../header/statsManager.h"
#include "../header/weapon.h"
#include "../header/trinket.h"
#include "../header/armor.h"
#include "../header/character.h"


TEST(getterTestsRoyalGuard, royalGuardInheritanceTest) {
    RoyalGuard guard(5, 5, 5, 5, 5, 5, false, "Knight guy");

    ASSERT_EQ(guard.getLevel(), 5);
    ASSERT_EQ(guard.getHealth(), 5);
    ASSERT_EQ(guard.getMaxHealth(), 5);
    ASSERT_EQ(guard.getDamage(), 5);
    ASSERT_EQ(guard.getMagicResist(), 5);
    ASSERT_EQ(guard.getPhysicalResist(), 5);
    ASSERT_EQ(guard.getStatus(), false);
    ASSERT_EQ(guard.getName(), "Knight guy");
}


TEST(calcTests, royalGuardCalcTurnTest) {
    RoyalGuard guard(4, 4, 4, 4, 4, 4, false, "Knight guy");

    Character character;
    int baseDMG = character.getBaseDamage();
    int baseHP = character.getBaseHP();
    int baseMR = character.getBaseMagicResist();
    int basePR = character.getBasePhysicalResist();
    Weapon weapon("knife", 5, 5, "physical");
    Armor armor("helmet", 1, 5, 1, 2);  
    Armor armorTwo("boots", 1, 5, 2, 1);         
    Trinket trinket("locket", 5, 5);  
    StatsManager* sm = new StatsManager();

    sm->updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
    //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 5 + (1 * 10) = 25

    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 2 = 3
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 1 = 2

    //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 1 = 2
    //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 2 = 3

    guard.calculateTurn(sm);
    EXPECT_EQ(sm->getCurrentHP(), 23);

    sm->updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armorTwo, &trinket, 1);
    guard.calculateTurn(sm);
    EXPECT_EQ(sm->getCurrentHP(), 23);
}
//******************************************************
#include "../header/screens/screen.h"

class MockScreen : public Screen{
  public:
    MockScreen(std::string filename, User* user): Screen(filename, user){}
    MOCK_METHOD((Screen*), processOption, (int, bool&), (override));
    MOCK_METHOD((void), displayScreen, (), (override));
};

TEST(screenAbstractTest, constructorTest){
    EXPECT_NO_THROW(Screen* testscreen = new MockScreen("filename", nullptr););
}

//******************************************************
#include "../header/spell.h"

class MockSpell: public Spell{
    public:
        MockSpell(const std::string& sc, int slt): Spell(sc, slt) {}
        MOCK_METHOD((void), doSpell, (int&, int&, int, int&, Enemy*), (override));
};

TEST(getterTestsSpell, getSpellClass){
    MockSpell mockSpell("Class1", 1);
    std::string spellClass = mockSpell.getSpellClass();
    EXPECT_TRUE(spellClass == "Class1");
}

TEST(getterTestsSpell, getSpellLevelThreshold){
    MockSpell mockSpell("Class1", 1);
    int spellLevelThreshold = mockSpell.getSpellLevelThreshold();
    EXPECT_EQ(spellLevelThreshold, 1);
}
//******************************************************
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
//******************************************************
#include "../header/screens/screen.h"

TEST(travelTests, displayTest){
    User* testUser = new User();
    Screen* travel = new Travel("travelScreen.txt", testUser);
    EXPECT_NO_THROW(travel->displayScreen());
}

TEST(travelTests, processOptionNot1or2){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* travel = new Travel("travelScreen.txt", testUser);
    EXPECT_EQ(travel->processOption(0, dummyRunning), travel);
}

TEST(travelTests, processOption1){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* travel = new Travel("travelScreen.txt", testUser);
    EXPECT_NE(travel->processOption(1, dummyRunning), travel);
}

TEST(travelTests, processOption2){
    User* testUser = new User();
    bool dummyRunning = true;
    Screen* travel = new Travel("travelScreen.txt", testUser);
    EXPECT_NE(travel->processOption(2, dummyRunning), travel);
}

//******************************************************
#include "../header/trinket.h"

TEST(getterTestTrinket, getNameTest) {
    Trinket trink("necklace", 5, 5);
    std::string testName = trink.getName();

    EXPECT_EQ(testName, "necklace");
}

TEST(getterTestsTrinket, getTypeTest) {
    Trinket trink("necklace", 5, 5);
    std::string testType = trink.getType();

    EXPECT_EQ(testType, "trinket");
}

TEST(getterTestsTrinket, getLevelTest) {
    Trinket trink("necklace", 5, 5);
    int testLevel = trink.getLevel();

    EXPECT_EQ(testLevel, 5);
}

TEST(calcTest, calcValueTest) {
    Trinket trink("necklace", 5, 5);
    int testValue = trink.calcValue();

    EXPECT_EQ(testValue, 25);
}
//******************************************************
#include "../header/user.h"

TEST(userConstructorTests, overloadedConstructorTest){
    
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();

    User u(1, 2, em, c, sm, im);

    EXPECT_EQ(u.getLevel(), 1);
    EXPECT_EQ(u.getXp(), 2);
    EXPECT_EQ(u.getEncounterManager(), em);
    EXPECT_EQ(u.getCharacterClass(), c);
    EXPECT_EQ(u.getStatsManager(), sm);
    EXPECT_EQ(u.getItemManager(), im);
}

TEST(userGetterTests, getUserLevel){
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, im);
    EXPECT_EQ(u.getLevel(), 1);
}

TEST(userGetterTests, getUserXp){
    
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, im);
    EXPECT_EQ(u.getXp(), 2);
}


TEST(userGetterTests, getUserEncounterManager){
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, nullptr);
    EXPECT_EQ(u.getEncounterManager(), em);
}



TEST(userGetterTests, getUserCharacterClass){
    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, im);
    EXPECT_EQ(u.getCharacterClass(), c);
}

TEST(userGetterTests, getUserStatsManager){
    

    Character* c = new Character();
    StatsManager* sm = new StatsManager();
    ItemManager* im = new ItemManager();
    EncounterManager* em = new EncounterManager();
    User u(1, 2, em, c, sm, im);
    EXPECT_EQ(u.getStatsManager(), sm);
}

TEST(userMethodTests, levelUp){
    User u(1, 5, nullptr, nullptr, nullptr, nullptr);
    u.levelUp();
    EXPECT_EQ(u.getLevel(), 2); 
    u.levelUp();
    EXPECT_EQ(u.getLevel(), 3);
}
//******************************************************
#include "../header/warrior.h"

TEST(warriorGetterTests, getHpTest){
    Warrior warrior;
    int testHP = warrior.getBaseHP();
    EXPECT_EQ(testHP, 15);
}

TEST(warriorGetterTests, getDamageTest){
    Warrior warrior;
    int testDamage = warrior.getBaseDamage();
    EXPECT_EQ(testDamage, 7);
}

TEST(warriorGetterTests, getPRTest){
    Warrior warrior;
    int testPR = warrior.getBasePhysicalResist();
    EXPECT_EQ(testPR, 5);
}

TEST(warriorGetterTests, getMRTest){
    Warrior warrior;
    int testMR = warrior.getBaseMagicResist();
    EXPECT_EQ(testMR, 5);
}

TEST(warriorGetterTests, getClassNameTest){
    Warrior warrior;
    std::string testName = warrior.getClassName();
    EXPECT_EQ(testName, std::string("Warrior").c_str());
}

TEST(warriorSpellGetterTests, getFirstClassNameTest){
    Warrior warrior;
    Spell* returnedSpell = warrior.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Slam").c_str());
}

TEST(warriorSpellGetterTests, getSecondClassNameTest){
    Warrior warrior;
    Spell* returnedSpell = warrior.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Shatter").c_str());
}

TEST(warriorSpellGetterTests, getThirdClassNameTest){
    Warrior warrior;
    Spell* returnedSpell = warrior.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellClass(), std::string("Bludgeon").c_str());
}

TEST(warriorSpellGetterTests, getFirstSpellLevelThreshold){
    Warrior warrior;
    Spell* returnedSpell = warrior.getFirstSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 1);
}

TEST(warriorSpellGetterTests, getSecondSpellLevelThreshold){
    Warrior warrior;
    Spell* returnedSpell = warrior.getSecondSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 2);
}

TEST(warriorSpellGetterTests, getThirdSpellLevelThreshold){
    Warrior warrior;
    Spell* returnedSpell = warrior.getThirdSpell();
    EXPECT_EQ(returnedSpell->getSpellLevelThreshold(), 3);
}

TEST(warriorSpellTests, testFirstDoSpell){
    Warrior warrior;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(warrior.getFirstSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(warriorSpellTests, testSecondDoSpell){
    Warrior warrior;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(warrior.getSecondSpell()->doSpell(hp, dmg, 1, gold, enemy););
}

TEST(warriorSpellTests, testThirdDoSpell){
    Warrior warrior;
    int hp = 1;
    int gold = 1;
    int dmg = 1;
    Enemy* enemy = new Orc();
    EXPECT_NO_THROW(warrior.getThirdSpell()->doSpell(hp, dmg, 1, gold, enemy););
}
//******************************************************
#include "../header/weapon.h"

TEST(weaponGetterTests, getDamageTest){
    Weapon weapon("fists", 1, 10, "physical");
    EXPECT_EQ(weapon.getDamage(), 10);
}
TEST(weaponGetterTests, getTypeTest) {
    Weapon weapon("fists", 1, 10, "physical");
    std::string testType = weapon.getType();
    EXPECT_EQ(testType, "weapon");
}

TEST(weaponGetterTests, getDamageTypeTest){
    Weapon weapon("fists", 1, 10, "physical");;
    EXPECT_STREQ(weapon.getDamageType().c_str(), std::string("physical").c_str());
}

TEST(weaponGetterTests, getWeaponNameTest){
    Weapon weapon("fists", 1, 10, "physical");
    EXPECT_EQ(weapon.getLevel(), 1);
}

TEST(weaponGetterTests, getWeaponLevelTest){
    Weapon weapon("fists", 1, 10, "physical");
    EXPECT_EQ(weapon.calcDamage(2), 20);
}

//******************************************************

#include "../header/bosspart1.h"
#include "../header/pirateBoss.h"
#include "../header/bosspart2.h"
#include "../header/finalBoss.h"
#include "../header/statsManager.h"
#include "../header/weapon.h"
#include "../header/trinket.h"
#include "../header/armor.h"
#include "../header/character.h"



// TEST(getterTests, inheritanceTest) {
//     BossPart1 tempBoss;

//     ASSERT_EQ(tempBoss.getLevel(), 0);
//     ASSERT_EQ(tempBoss.getHealth(), 0);
//     ASSERT_EQ(tempBoss.getMaxHealth(), 0);
//     ASSERT_EQ(tempBoss.getDamage(), 0);
//     ASSERT_EQ(tempBoss.getMagicResist(), 0);
//     ASSERT_EQ(tempBoss.getPhysicalResist(), 0);
//     ASSERT_EQ(tempBoss.getStatus(), false);
//     ASSERT_EQ(tempBoss.getName(), "");
// }

TEST(getterTestsPirateBoss, pirateBossInheritanceTest) {
    PirateBoss tempBoss(5, 5, 5, 5, 5, 5, false, "Captain Hook");

    ASSERT_EQ(tempBoss.getLevel(), 5);
    ASSERT_EQ(tempBoss.getHealth(), 5);
    ASSERT_EQ(tempBoss.getMaxHealth(), 5);
    ASSERT_EQ(tempBoss.getDamage(), 5);
    ASSERT_EQ(tempBoss.getMagicResist(), 5);
    ASSERT_EQ(tempBoss.getPhysicalResist(), 5);
    ASSERT_EQ(tempBoss.getStatus(), false);
    ASSERT_EQ(tempBoss.getName(), "Captain Hook");
}

TEST(getterTestsPirateBoss, finalBossInheritanceTest) {
    FinalBoss tempBoss(5, 5, 5, 5, 5, 5, false, "Joe");

    ASSERT_EQ(tempBoss.getLevel(), 5);
    ASSERT_EQ(tempBoss.getHealth(), 5);
    ASSERT_EQ(tempBoss.getMaxHealth(), 5);
    ASSERT_EQ(tempBoss.getDamage(), 5);
    ASSERT_EQ(tempBoss.getMagicResist(), 5);
    ASSERT_EQ(tempBoss.getPhysicalResist(), 5);
    ASSERT_EQ(tempBoss.getStatus(), false);
    ASSERT_EQ(tempBoss.getName(), "Joe");
    
}

TEST(calcTests, pirateCalculateTurnTest) {
  PirateBoss tempBoss(10, 10, 10, 10, 10, 10, false, "Captain Hook");

  Character character;
  int baseDMG = character.getBaseDamage();
  int baseHP = character.getBaseHP();
  int baseMR = character.getBaseMagicResist();
  int basePR = character.getBasePhysicalResist();
  Weapon weapon("knife", 5, 5, "physical");
  Armor armor("helmet", 5, 5, 5, 5);           
  Trinket trinket("locket", 5, 5);  
  StatsManager* sm = new StatsManager();

    sm->updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
  //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 5 + (1 * 10) = 25

  //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 5 = 6
  //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 5 = 6

  tempBoss.calculateTurn(sm);
  ASSERT_EQ(sm->getCurrentHP(), 21);

  tempBoss.dealDamage(6);
  sm->updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
  tempBoss.calculateTurn(sm);
  ASSERT_EQ(sm->getCurrentHP(), 16);
}

TEST(calcTests, finalBossCalculateTurnTest) {
  FinalBoss tempBoss(10, 10, 10, 10, 10, 10, false, "Captain Hook");

  Character character;
  int baseDMG = character.getBaseDamage();
  int baseHP = character.getBaseHP();
  int baseMR = character.getBaseMagicResist();
  int basePR = character.getBasePhysicalResist();
  Weapon weapon("knife", 5, 5, "physical");
  Armor armor("helmet", 5, 5, 5, 5);           
  Trinket trinket("locket", 5, 5);  
  StatsManager* sm = new StatsManager();

  sm->updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
  //  maxHP       =   characterBaseHealth + armorHealthBonus + (userLevel * 10) = 10 + 5 + (1 * 10) = 25

  //  currentMR   =   characterBaseMagicResist + armorMagicResistBonus = 1 + 5 = 6
  //  currentPR   =   characterBasePhysicalResist + armorPhysicalResistBonus = 1 + 5 = 6

  tempBoss.calculateTurn(sm);
  ASSERT_EQ(sm->getCurrentHP(), 21);

  tempBoss.dealDamage(8);
  sm->updateStats(baseDMG, baseHP, baseMR, basePR, &weapon, &armor, &trinket, 1);
  tempBoss.calculateTurn(sm);
  ASSERT_EQ(sm->getCurrentHP(), 13);

}

//******************************************************
int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
