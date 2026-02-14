#ifndef STATES_HH_INCLUDED
#define STATES_HH_INCLUDED


class Main {
    public:
    virtual void handle ()  = 0;
    virtual void process () = 0;
    virtual ~Main ()        = default;
};

void switchState (Main* newst);

class home : public Main {
    public:
    void handle () override;
    void process () override;

    virtual ~home () = default;

    private:
    int gotonum;
};
class gameplay : public Main {
    public:
    void handle () override;
    void process () override;


    virtual ~gameplay () = default;


    private:
    unsigned int timeElapsed = 0;
    int paused               = 3;
};
class settings : public Main {
    public:
    void handle () override;
    void process () override;


    virtual ~settings () = default;


    private:
    int mode = 0;
};
class credits : public Main {
    public:
    void handle () override;
    void process () override;


    virtual ~credits () = default;
};

#endif // STATES_HH_INCLUDED