[@react.component]
let make = () => {
  let (counter, setCounter) = React.useState(() => 0.0);

  <div
    style={ReactDOMStyle.make(
      ~padding="1em",
      ~display="grid",
      ~gridGap="1em",
      ~gridTemplateColumns="25px fit-content(20px) 25px",
      (),
    )}>
    <button onClick={_evt => setCounter(v => v -. 0.5)}> {React.string("-")} </button>
    <span> {counter |> Float.to_string |> React.string} </span>
    <button onClick={_evt => setCounter(v => v +. 1.5)}> {React.string("+")} </button>
  </div>;
};
