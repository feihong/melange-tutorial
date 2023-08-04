Random.self_init();

[@react.component]
let make = () => {
  let (number, _) = React.useState(() => Random.int(100) + 1);
  let (inputValue, setInputValue) = React.useState(() => "");
  let (guess, setGuess) = React.useState(() => None);

  <div>
    {React.string("Guess a number between 1 and 100")}
    <form
      onSubmit={evt => {
        ReactEvent.Form.preventDefault(evt);
        setGuess(_ => int_of_string_opt(inputValue));
      }}>
      <input
        autoFocus=true
        value=inputValue
        onChange={evt => setInputValue(_ => ReactEvent.Form.target(evt)##value)}
      />
    </form>
    <div>
      {switch (guess) {
       | None => React.null
       | Some(guess) when guess > number => React.string("Too high")
       | Some(guess) when guess < number => React.string("Too low")
       | Some(_guess) => React.string("You win!")
       }}
    </div>
  </div>;
};
