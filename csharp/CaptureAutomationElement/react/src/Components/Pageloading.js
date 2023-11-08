import React, { useEffect, useState } from 'react';

import './Pageloadin.css';

export default function Pageloading() {
   const [logoClass, setLogoClass] = useState('logo');

  useEffect(() => {
    setTimeout(() => {
      setLogoClass('logo move-to-right');
    }, 1000);
  }, []);

  return (
    <div className={logoClass}>

    </div>
  )
}
