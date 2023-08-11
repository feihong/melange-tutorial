let initFahrenheit = {js|? °F|js};

[@react.component]
let make = () => {
  let (celsius, setCelsius) = React.useState(() => "");
  let (fahrenheit, setFahrenheit) = React.useState(() => initFahrenheit);

  <div>
    <input
      value=celsius
      onChange={evt => {
        let newValue = ReactEvent.Form.target(evt)##value |> String.trim;
        setCelsius(_ => newValue);

        let fahrenheit =
          switch (float_of_string_opt(newValue)) {
          | None when newValue == "" => initFahrenheit
          | None => "error"
          | Some(celsius) =>
            let fahrenheit = 9.0 /. 5.0 *. celsius +. 32.0;
            string_of_float(fahrenheit) ++ {js| °F|js};
          };
        setFahrenheit(_ => fahrenheit);
      }}
    />
    {React.string({js|°C = |js})}
    <span> {React.string(fahrenheit)} </span>
  </div>;
};
