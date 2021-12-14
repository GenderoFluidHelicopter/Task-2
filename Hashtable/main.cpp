#include <iostream>
#include "HashTable.h"
#include <gtest/gtest.h>


class HashTableTest : public testing::Test {
protected:
    void SetUp() override {
        h1.insert("Andrew", {20, 20});
        h1.insert("Nikita", {22, 100});
        h2.insert("Daniil", {28, 70});
    }
    HashTable h0;
    HashTable h1;
    HashTable h2;

};
TEST_F(HashTableTest, T1) {
    h1.swap(h2);
    EXPECT_EQ(h2.size(), 2);
    EXPECT_EQ(h2["Andrew"].weight, 20);
}
TEST_F(HashTableTest, T2) {
    bool r = h1.erase("Nikita");
    EXPECT_EQ(r, true);
    EXPECT_EQ(h1["Nikita"].weight, 80);
}
TEST_F(HashTableTest, T3) {
    bool r = h1.empty();
    EXPECT_EQ(r, false);
    r = h0.empty();
    EXPECT_EQ(r, true);
}
TEST_F(HashTableTest, T4) {
    bool r = h1.contains("Timur");
    EXPECT_EQ(r, false);
    r = h1.contains("Nikita");
    EXPECT_EQ(r, true);
}
TEST_F(HashTableTest, T5) {
    Value& s = h1.at("Nikita");
    EXPECT_EQ(s.weight, 100);
    ASSERT_ANY_THROW(h1.at("Vova"));
}
TEST_F(HashTableTest, T6) {
    bool r1 = h1 == h2;
    EXPECT_EQ(r1, false);
    bool r2 = h1 != h2;
    EXPECT_EQ(r2, true);
    unsigned int r3 = h1["Nikita"].weight;
    EXPECT_EQ(r3, 100);
    h1 = h2;
    r1 = h1 == h2;
    EXPECT_EQ(r1, true);
}
TEST_F(HashTableTest, T7) {
    HashTable h3 = h1;
    EXPECT_EQ(h3.size(), 2);
    bool r0 = h3.contains("Andrew");
    EXPECT_EQ(r0, true);
    bool r1 = h3.contains("Nikita");
    EXPECT_EQ(r1, true);
    bool r2 = h3.contains("someone");
    EXPECT_EQ(r2, false);

}
TEST_F(HashTableTest, T8) {
    HashTable h4 = std::move(h2);
    bool r0 = h4.contains("Daniil");
    EXPECT_EQ(r0, true);

}