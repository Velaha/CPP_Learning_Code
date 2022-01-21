class MinuteHand {
private:
    int _minutes = 0;

public:
    int  get_minutes() { return _minutes; }
    void advance() { _minutes += 1; }
};