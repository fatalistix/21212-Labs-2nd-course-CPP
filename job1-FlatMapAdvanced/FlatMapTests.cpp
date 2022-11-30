#include <vector>
#include <string>
#include <algorithm>

#include "gtest/gtest.h"

#include "FlatMap.h"

// Pairs of keys and values which will be contained in FlatMap
std::vector<std::string> keys     = {"1032", "1Abc", "AAw", "::l", "\\l", "\10", "409a", "a505", "  04\n", "", "ggg"};
std::vector<int>         values   = {3,      10,     25,    16,    99,    0,     317,    457,    2,        0,   777};

// Keys that wouldn't be in container
std::vector<std::string> not_keys = {"5",    "x",    "not", "a ",  "key", "",    "\255"};

TEST(Constructors, DefaultConstructor)
{
    FlatMap<std::string, std::vector<int>> flatmap;
    EXPECT_EQ(flatmap.GetVectorOfKeys()  .size(), 0);
    EXPECT_EQ(flatmap.GetVectorOfValues().size(), 0);
}

TEST(Insert, InsertWithoutCollision)
{
    // Creates FlatMap, creates std::vector of pairs
    FlatMap<std::string, int> flatmap;
    std::vector<std::pair<std::string, int>> buf;

    for (size_t i = 0; i < keys.size(); i++)
    {
        // Inserts all keys and values to both FlatMap and std::vector
        EXPECT_TRUE(flatmap.insert(std::make_pair(keys[i], values[i])));
        buf.emplace_back(std::make_pair(keys[i], values[i]));

        // Sorts std::vector by keys so these containers are similar
        sort(buf.begin(), buf.end(),
             [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {return a.first < b.first;});

        // Vector of only keys and vector of only values
        std::vector<std::string> buf_keys;
        std::vector<int> buf_values;

        // Fills these vectors
        for (auto& c : buf)
        {
            buf_keys  .push_back(c.first);
            buf_values.push_back(c.second);
        }

        // Checks if keys and values are EQ
        EXPECT_EQ(flatmap.GetVectorOfKeys(),   buf_keys);
        EXPECT_EQ(flatmap.GetVectorOfValues(), buf_values);
    }
}

TEST(Insert, InsertWithCollision)
{
    // Creates FlatMap, creates std::vector of pairs
    FlatMap<std::string, int> flatmap;
    std::vector<std::pair<std::string, int>> buf;

    // Inserts all keys and values to both FlatMap and std::vector
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_TRUE(flatmap.insert(std::make_pair(keys[i], values[i])));
        buf.emplace_back(std::make_pair(keys[i], values[i]));
    }
    // Sorts std::vector by keys so these containers are similar
    sort(buf.begin(), buf.end(),
         [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {return a.first < b.first;});

    // Vector of only keys and vector of only values
    std::vector<std::string> buf_keys;
    std::vector<int> buf_values;

    // Fills these vectors
    for (auto& c : buf)
    {
        buf_keys  .push_back(c.first);
        buf_values.push_back(c.second);
    }

    // Checks inserting of keys with same values as in containers
    // Expect that changes nothing
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_FALSE(flatmap.insert(std::make_pair(keys[i], values[i])));
        EXPECT_EQ(flatmap.GetVectorOfKeys(),   buf_keys);
        EXPECT_EQ(flatmap.GetVectorOfValues(), buf_values);
    }

    // Checks inserting of keys with same values as in containers
    // Expect that changes nothing
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_FALSE(flatmap.insert(std::make_pair(keys[i], values[values.size() - 1 - i])));
        EXPECT_EQ(flatmap.GetVectorOfKeys(), buf_keys);
        EXPECT_EQ(flatmap.GetVectorOfValues(), buf_values);
    }
}

TEST(Erase, Clear)
{
    // Creates FlatMap
    FlatMap<std::string, int> flatmap;

    // Checks that FlatMap with j + 1 elements will be cleared correctly
    for (size_t j = 0; j < keys.size(); j++)
    {
        // Pushes first j + 1 elements
        for (size_t i = 0; i < j + 1; i++)
        {
            EXPECT_TRUE(flatmap.insert(std::make_pair(keys[i], values[i])));
        }
        // Checks is cleared FlatMap EQ to FlatMap from default constructor
        flatmap.clear();
        FlatMap<std::string, int> buf;
        EXPECT_EQ(buf, flatmap);
    }
}

TEST(Erase, Erase)
{
    // Creates FlatMap, creates std::vector of pairs
    FlatMap<std::string, int> flatmap;
    std::vector<std::pair<std::string, int>> buf;

    // Inserts all keys and values to both FlatMap and std::vector
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_TRUE(flatmap.insert(std::make_pair(keys[i], values[i])));
        buf.emplace_back(std::make_pair(keys[i], values[i]));
    }
    // Sorts std::vector by keys so these containers are similar
    sort(buf.begin(), buf.end(),
         [](std::pair<std::string, int>& a, std::pair<std::string, int>& b) {return a.first < b.first;});

    // Creates std::vector of keys which will be erased
    // Helps to easily compare std::vector of pairs after erase and FlatMap
    std::vector<std::string> keys_for_erase(flatmap.GetVectorOfKeys());

    // Deletes i-key
    for (size_t i = 0; i < keys_for_erase.size(); i++)
    {
        // Copy of std::vector of pairs
        // But without i-element
        std::vector<std::pair<std::string, int>> b(buf);
        // Same about copy of FlatMap
        FlatMap<std::string, int> f(flatmap);

        // Erases element from both FlatMap and std::vector
        EXPECT_TRUE(f.erase(keys_for_erase[i]));
        b.erase(b.begin() + int(i));

        // Vector of only keys and vector of only values
        std::vector<std::string> buf_keys;
        std::vector<int> buf_values;

        // Fills these vectors
        for (auto& c : b)
        {
            buf_keys  .push_back(c.first);
            buf_values.push_back(c.second);
        }

        // Expect, that after removing they'll be EQ
        EXPECT_EQ(f.GetVectorOfKeys(),   buf_keys);
        EXPECT_EQ(f.GetVectorOfValues(), buf_values);
    }

    // Erases border elements in FlatMap
    // Helps to check critical situations
    flatmap.erase("");
    flatmap.erase("ggg");

    // Erases border elements in std::vector
    buf.erase(buf.begin());
    buf.erase(buf.end() - 1);

    // Vector of only keys and vector of only values
    std::vector<std::string> buf_keys;
    std::vector<int> buf_values;

    // Fill these std::vectors
    for (auto& c : buf)
    {
        buf_keys  .push_back(c.first);
        buf_values.push_back(c.second);
    }

    // Tries to erase with wrong keys
    // Expect that nothing changes
    for (auto& c : not_keys)
    {
        EXPECT_FALSE(flatmap.erase(c));
        EXPECT_EQ(flatmap.GetVectorOfKeys(), buf_keys);
        EXPECT_EQ(flatmap.GetVectorOfValues(), buf_values);
    }
}

// Default Copy Constructor checker for different number of elements
TEST(Constructors, CopyConstructor)
{
    FlatMap<std::string, int> flatmap;
    EXPECT_EQ(flatmap, FlatMap(flatmap));

    for (size_t i = 0; i < keys.size(); i++)
    {
        flatmap.insert(std::make_pair(keys[i], values[i]));
        EXPECT_EQ(flatmap, FlatMap(flatmap));
    }
}

// Default Move Constructor checker for different number of elements
// Instead of Copy Constructors needs 2 copies of 1 object
TEST(Constructors, MoveConstructor)
{
    FlatMap<std::string, int> flatmap;
    {
        FlatMap<std::string, int> buf;
        EXPECT_EQ(flatmap, FlatMap(std::move(buf)));
    }

    for (size_t i = 0; i < keys.size(); i++)
    {
        flatmap.insert(std::make_pair(keys[i], values[i]));
        FlatMap<std::string, int> buf;
        for (size_t j = 0; j < i + 1; j++)
        {
            buf.insert(std::make_pair(keys[j], values[j]));
        }
        EXPECT_EQ(flatmap, FlatMap(std::move(buf)));
    }
}


// Tests copy assign operator same as Copy constructor
TEST(Assignment, CopyAssignment)
{
    FlatMap<std::string, int> flatmap;
    FlatMap<std::string, int> flatmap_comp;
    EXPECT_EQ(flatmap, flatmap_comp = flatmap);

    for (size_t i = 0; i < keys.size(); i++)
    {
        flatmap.insert(std::make_pair(keys[i], values[i]));
        EXPECT_EQ(flatmap, flatmap_comp = flatmap);
    }
}

// Tests move assignment
TEST(Assignment, MoveAssignment)
{
    // always need 3 copy of object
    FlatMap<std::string, int> flatmap;          // original one
    FlatMap<std::string, int> flatmap_comp;     // which will be left operand
    // Creates scope for just 1 test
    // because in every test we need to recreate right operand
    {
        FlatMap<std::string, int> flatmap_move; // which will be right operand
        EXPECT_EQ(flatmap, flatmap_comp = std::move(flatmap_move));
    }

    for (size_t i = 0; i < keys.size(); i++)
    {
        // Inserts value to origin
        flatmap.insert(std::make_pair(keys[i], values[i]));
        // Creates move object
        FlatMap<std::string, int> flatmap_move;
        // Fills it
        for (size_t j = 0; j < i + 1; j++)
        {
            flatmap_move.insert(std::make_pair(keys[j], values[j]));
        }
        EXPECT_EQ(flatmap, flatmap_comp = std::move(flatmap_move));
    }
}

TEST(Contains, ContainsTrue)
{
    // Creates FlatMap
    FlatMap<std::string, int> flatmap;

    // Inserts all keys and values to FlatMap and checks
    // if they are contained on every step of addition
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_TRUE(flatmap.insert(std::make_pair(keys[i], values[i])));
        for (size_t j = 0; j < i + 1; j++)
        {
            EXPECT_TRUE(flatmap.contains(keys[j]));
        }
    }
}

TEST(Contains, ContainsFalse)
{
    // Creates FlatMap
    FlatMap<std::string, int> flatmap;
    EXPECT_FALSE(flatmap.contains(keys[0]));

    // Inserts all keys and values to FlatMap
    // And checks that method of keys that are not contained returns false
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_TRUE(flatmap.insert(std::make_pair(keys[i], values[i])));
        for (size_t j = i + 1; j < keys.size(); j++)
        {
            EXPECT_FALSE(flatmap.contains(keys[j]));
        }
        for (size_t j = 0; j < not_keys.size() - 2; j++)
        {
            EXPECT_FALSE(flatmap.contains(not_keys[j]));
        }
    }
}

TEST(GetElement, NotSecure)
{
    // Creates FlatMap and Map for comparing
    FlatMap<std::string, int> flatmap;
    std::map<std::string, int> m;

    // Inserts all keys and values to FlatMap and checks
    // if they are contained on every step of addition
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_TRUE(flatmap.insert(std::make_pair(keys[i], values[i])));
        m.insert(std::make_pair(keys[i], values[i]));
        for (size_t j = 0; j < i + 1; j++)
        {
            EXPECT_EQ(flatmap[keys[j]], m[keys[j]]);
        }
    }
}

TEST(GetElement, Secure)
{
    // Creates FlatMap and Map for comparing
    FlatMap<std::string, int> flatmap;
    std::map<std::string, int> m;

    // Inserts all keys and values to FlatMap and checks
    // if they are contained on every step of addition
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_TRUE(flatmap.insert(std::make_pair(keys[i], values[i])));
        m.insert(std::make_pair(keys[i], values[i]));
        for (size_t j = 0; j < i + 1; j++)
        {
            EXPECT_EQ(flatmap.at(keys[j]), m.at(keys[j]));
        }
        for (size_t j = i + 1; j < keys.size(); j++)
        {
            EXPECT_THROW(flatmap.at(keys[j]), std::out_of_range);
        }
    }
}

TEST(Nodiscard, Empty)
{
    FlatMap<std::string, int> flatmap;
    EXPECT_TRUE(flatmap.empty());
    flatmap.insert(std::make_pair(keys[0], values[0]));
    EXPECT_FALSE(flatmap.empty());
}

TEST(Nodiscard, Size)
{
    FlatMap<std::string, int> flatmap;
    EXPECT_EQ(flatmap.size(), 0);
    flatmap.insert(std::make_pair(keys[0], values[0]));
    EXPECT_NE(flatmap.size(), 0);
}

TEST(EQ, EQ)
{
    FlatMap<std::string, int> flatmap, flatmap_comp;
    for (size_t i = 0; i < keys.size(); i++)
    {
        EXPECT_TRUE(flatmap == flatmap_comp);
        flatmap.insert(std::make_pair(keys[i], values[i]));
        EXPECT_FALSE(flatmap == flatmap_comp);
        flatmap_comp.insert(std::make_pair(keys[i], values[i]));
        EXPECT_TRUE(flatmap == flatmap_comp);
        flatmap.erase(keys[i]);
        EXPECT_FALSE(flatmap == flatmap_comp);
        flatmap.insert(std::make_pair(keys[i], values[i]));
        EXPECT_TRUE(flatmap == flatmap_comp);
    }
}

TEST(Swap, Swap)
{
    FlatMap <std::string, int> flatmap_swap, flatmap_swap1;
    for (size_t i = 0; i < (keys.size() >> 1) << 1; i++)
    {
        flatmap_swap .insert(std::make_pair(keys[i],     values[i]));
        flatmap_swap1.insert(std::make_pair(keys[i + 1], values[i + 1]));
    }
    FlatMap <std::string, int> flatmap_copy = flatmap_swap, flatmap_copy1 = flatmap_swap1;
    flatmap_swap.swap(flatmap_swap1);
    EXPECT_TRUE(flatmap_swap  == flatmap_copy1);
    EXPECT_TRUE(flatmap_swap1 == flatmap_copy);
    EXPECT_FALSE(flatmap_swap.erase(keys[0]));
    EXPECT_TRUE (flatmap_swap.erase(keys[1]));

    flatmap_copy  = flatmap_swap;
    flatmap_copy1 = flatmap_swap1;
    flatmap_swap1.swap(flatmap_swap);
    EXPECT_TRUE(flatmap_swap  == flatmap_copy1);
    EXPECT_TRUE(flatmap_swap1 == flatmap_copy);
}



int main(int argc, char* argv[])
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
