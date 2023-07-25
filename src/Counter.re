[@react.component]
let make = () => {
  let (counter, setCounter) = React.useState(() => 0);

  <div
    style={ReactDOMStyle.make(
      ~padding="1em",
      ~display="grid",
      ~gridGap="1em",
      ~gridTemplateColumns="25px fit-content(20px) 25px",
      (),
    )}>
    <button onClick={_evt => setCounter(v => v - 1)}> "-"->React.string </button>
    <span> {React.string(Int.to_string(counter))} </span>
    <button onClick={_evt => setCounter(v => v + 1)}> {React.string("+")} </button>
  </div>;
};
