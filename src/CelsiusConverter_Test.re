let getValueFromEvent = (evt): string => ReactEvent.Form.target(evt)##value;

let convert = celsius => 9.0 /. 5.0 *. celsius +. 32.0;

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");
  let (fahrenheit, setFahrenheit) = React.useState(() => None);

  <div>
    <input
      value=celsius
      onChange={evt => {
        let newCelsius = getValueFromEvent(evt);
        setCelsius(_ => newCelsius);
        let newFahrenheit =
          newCelsius
          |> float_of_string_opt
          |> Option.map(convert)
          |> Option.map(Js.Float.toFixedWithPrecision(~digits=2));
        setFahrenheit(_ => newFahrenheit);
      }}
    />
    {React.string({js|°C = |js})}
    {(
       switch (celsius, fahrenheit) {
       | ("", _) => {js|? °F|js}
       | (_, None) => "error"
       | (_, Some(fahrenheit)) => fahrenheit ++ {js| °F|js}
       }
     )
     |> React.string}
  </div>;
};
