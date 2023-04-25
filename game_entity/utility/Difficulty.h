#pragma once

enum class Difficulty {
    EASY = 50,
    MEDIUM = 35,
    HARD = 20,
    EXTREME = 5,
    JACKPOT = 1
};

class Multiplier {
    float val;

    Multiplier(float v) : val(v) {}

public:
    static const Multiplier EASY;
    static const Multiplier MEDIUM;
    static const Multiplier HARD;
    static const Multiplier EXTREME;
    static const Multiplier JACKPOT;

    static float getMultiplier(Difficulty diff) {
        switch (diff) {
            case Difficulty::EASY:
                return Multiplier::EASY.val;
            case Difficulty::MEDIUM:
                return Multiplier:: MEDIUM.val;
            case Difficulty::HARD:
                return Multiplier::HARD.val;
            case Difficulty::EXTREME:
                return Multiplier::EXTREME.val;
            case Difficulty::JACKPOT:
                return Multiplier::JACKPOT.val;
            default:
                return Multiplier::EASY.val;
        }
    }
};

inline const Multiplier Multiplier::EASY(1.2f);
inline const Multiplier Multiplier::MEDIUM(2.2f);
inline const Multiplier Multiplier::HARD(5.0f);
inline const Multiplier Multiplier::EXTREME(12.0f);
inline const Multiplier Multiplier::JACKPOT(25.0f);

inline Difficulty getDifficulty(int val) {
    switch (val) {
        case 1:
            return Difficulty::EASY;
        case 2:
            return Difficulty::MEDIUM;
        case 3:
            return Difficulty::HARD;
        case 4:
            return Difficulty::EXTREME;
        default:
            return Difficulty::EASY;
    }
}
