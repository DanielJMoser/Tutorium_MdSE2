#ifndef UEZ4_TUT_EXCEPTIONS_H
#define UEZ4_TUT_EXCEPTIONS_H

#include <stdexcept>
#include <string>

// Base game exception class, welche einen Constructor mit einer Fehlermeldung providet.
class game_error : public std::runtime_error {
public:
    explicit game_error(const std::string &msg) : std::runtime_error(msg) {}
};

// Spezifische Exception für den Fall, dass das Inventar voll ist
class inventory_full_exception : public game_error {
public:
    explicit inventory_full_exception(const std::string &msg = "Inventory is full")
            : game_error(msg) {}
};

// Spezifische Exception für den Fall, dass ein ungültiger Index verwendet wird
class index_invalid_exception : public game_error {
public:
    explicit index_invalid_exception(const std::string &msg = "Invalid index accessed")
            : game_error(msg) {}
};

// Spezifische Exception für den Fall, dass ein ungültiger Gegenstand manipuliert wird
class item_invalid_exception : public game_error {
public:
    explicit item_invalid_exception(const std::string &msg = "Invalid item operation attempted")
            : game_error(msg) {}
};

// Spezifische Exception für den Fall, dass ein ungültiger Wert verwendet wird
// z.B. negativer Wert für Gold
class value_invalid_exception : public game_error {
public:
    explicit value_invalid_exception(const std::string &msg = "Invalid value provided")
            : game_error(msg) {}
};

#endif // UEZ4_TUT_EXCEPTIONS_H
