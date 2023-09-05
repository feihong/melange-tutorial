module Css = {
  let counter = [%cx
    {|
    padding: 1em;
    display: grid;
    grid-gap: 1em;
    grid-template-columns: 1.8em 2em 1.8em;
  |}
  ];

  let button = [%cx {|
    background-color: lightblue;

    :hover {
      background-color: lightcyan;
    }
  |}];

  let number = value => {
    let color =
      switch (value) {
      | value when value < 0 => CssJs.red
      | value when value > 0 => CssJs.green
      | _ => CssJs.blue
      };
    [%cx {|
    text-align: center;
    font-size: 2em;
    color: $(color);
  |}];
  };
};

[@react.component]
let make = () => {
  let (counter, setCounter) = React.useState(() => 0);

  <div className=Css.counter>
    <button className=Css.button onClick={_evt => setCounter(v => v - 1)}> {React.string("-")} </button>
    <span className={Css.number(counter)}> {counter |> Int.to_string |> React.string} </span>
    <button className=Css.button onClick={_evt => setCounter(v => v + 1)}> {React.string("+")} </button>
  </div>;
};
