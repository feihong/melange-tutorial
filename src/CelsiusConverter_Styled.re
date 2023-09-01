module Css = {
  let errorInput = [%cx {|
    background-color: pink;
  |}];

  let errorText = [%cx {|
    color: red;
  |}];
};

let getValueFromEvent = (evt): string => ReactEvent.Form.target(evt)##value;

let convert = celsius => 9.0 /. 5.0 *. celsius +. 32.0;

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");

  let fahrenheitString =
    String.trim(celsius) == ""
      ? Some({js|? °F|js})
      : (
        switch (celsius |> float_of_string_opt |> Option.map(convert)) {
        | None => None
        | Some(fahrenheit) when fahrenheit < (-128.6) => Some({js|Unreasonably cold🥶|js})
        | Some(fahrenheit) when fahrenheit > 212.0 => Some({js|Unreasonably hot🥵|js})
        | Some(fahrenheit) => Some(Js.Float.toFixedWithPrecision(fahrenheit, ~digits=2) ++ {js| °F|js})
        }
      );

  <div>
    <input
      className={fahrenheitString == None ? Css.errorInput : ""}
      value=celsius
      onChange={evt => setCelsius(_ => getValueFromEvent(evt))}
    />
    {React.string({js|°C = |js})}
    {switch (fahrenheitString) {
     | None => <span className=Css.errorText> {React.string("error")} </span>
     | Some(fahrenheitString) => React.string(fahrenheitString)
     }}
  </div>;
};
