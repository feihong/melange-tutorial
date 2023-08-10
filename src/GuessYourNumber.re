type phase =
  | Start
  | Guessing(int, int)
  | Win(int);

[@react.component]
let make = () => {
  let (phase, setPhase) = React.useState(() => Start);

  <div>
    {switch (phase) {
     | Start =>
       <>
         <div> {React.string("Think of a number between 1 and 100, then hit Start")} </div>
         <button onClick={_evt => setPhase(_ => Guessing(1, 100))}> {React.string("Start")} </button>
       </>
     | Guessing(low, high) =>
       let guess = low + (high - low) / 2;
       <>
         <div> {React.string("Is your number " ++ Int.to_string(guess) ++ "?")} </div>
         <button onClick={_evt => setPhase(_ => Guessing(low, guess - 1))}> {React.string("Lower")} </button>
         <button onClick={_evt => setPhase(_ => Win(guess))}> {React.string("Yes")} </button>
         <button onClick={_evt => setPhase(_ => Guessing(guess + 1, high))}> {React.string("Higher")} </button>
       </>;
     | Win(number) => React.string("Your number is " ++ Int.to_string(number) ++ "!")
     }}
  </div>;
};
