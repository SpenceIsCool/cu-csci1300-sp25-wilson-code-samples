/**
 * Counter.hpp
 *
 * A header file
 *
 * An easy to read explanation of what the Counter class can do
 */


/**
 * Counter
 *
 * a two digit counter display
 * you can look at it to know it's count
 * click it 1 or many times to increase it's count
 * or reset its count to 0
 *
 * looks like this, but if it only had 2 digits: https://www.google.com/imgres?q=counter&imgurl=https%3A%2F%2Fwww.universalmedicalinc.com%2Fmedia%2Fcatalog%2Fproduct%2Fcache%2F93f6ee08602653d43dda00297d18a5f3%2Fh%2Fs%2Fhs6594_lab-hand-tally-counter_1.jpg&imgrefurl=https%3A%2F%2Fwww.universalmedicalinc.com%2Flab-hand-tally-counter.html&docid=kemmUiZKaud6FM&tbnid=t0dshwBmTa-XCM&vet=12ahUKEwi608fOk5SMAxXNFzQIHcarJrgQM3oECCMQAA..i&w=840&h=840&hcb=2&ved=2ahUKEwi608fOk5SMAxXNFzQIHcarJrgQM3oECCMQAA
 */
class Counter
{
public:
    Counter( );
    Counter( int startValue );
    void look() const;
    void click();
    void click( unsigned int positiveValue );
    void reset();
private:
    // count maxes at 255 so it's just big enough for us
    char count;
    // keep it 2 digits long
    const int MAX = 100;
};  // don't forget the semi-colon


